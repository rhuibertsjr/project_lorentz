/* Copyright (C) 2023 Ren� Huiberts 
   All rights reserved. */

#include <string.h>

//= rhjr: arena allocator

internal Arena *
memory_arena_reserve (u64 size)
{
  Arena *result = NULL;

  // rhjr: request memory from platform, and commit the initial memory.
  void* ptr = platform_memory_reserve(size);
  platform_memory_commit(ptr, sizeof(Arena));

  result = (Arena*) ptr;
  result->memory = ptr;
  result->offset = 0 + sizeof(Arena);
  result->size = size - sizeof(Arena);

  assert(result != 0, "Couldn't reserve memory from the Operating system");
  return result;
}

internal Arena *
memory_arena_reserve_default ()
{
  return memory_arena_reserve(mb(1));
}

internal void *
memory_arena_alloc (Arena *arena, u64 size)
{
  void *result;

  size = memory_align_forward(size, MEMORY_ARENA_DEFAULT_ALIGNMENT);

  if (arena->offset + size <= arena->size)
  {
    // rhjr: make sure arena->offset is used as a pointer.
    result = (void*)((ptr64) arena->memory + (ptr64) arena->offset);
    arena->offset += size;

    // rhjr: mark memory as used/usable.
    platform_memory_commit(result, size);

    memset(result, 0, size);
  }

  assert(result != 0, "Arena is out of space.");
  return result;
}

void
memory_arena_free (Arena *arena)
{
  platform_memory_release(arena, arena->size);
}

u64
memory_align_forward (u64 ptr, u64 align)
{
  u64 result, offset, modulo;
    
	result = ptr;
	offset = (u64) align;
	modulo = result & (offset - 1);
    
	if (modulo != 0)
  {
    // rhjr: 'p' is not aligned, push the address to the next aligned value.
		result += offset - modulo;
	}

	return result;
}

ArenaScratch
memory_begin_temp (Arena *arena)
{
  ArenaScratch result = { arena, arena->offset };
  return result;
}

void
memory_end_temp (ArenaScratch *arena)
{
  arena->arena->offset = arena->offset;
  return;
}

//= rhjr: scratch memory

thread_local Arena *_memory_scratch_pool[MEMORY_ARENA_SCRATCH_POOL_COUNT];

internal ArenaScratch
memory_get_scratch_pool(Arena **conflicting_arena, u32 count)
{
  //- rhjr: initialization
  if (_memory_scratch_pool[0] == 0)
  {
    assert(
      MEMORY_ARENA_SCRATCH_POOL_COUNT <= 4, "Exceeded max amount of arenas"); 
    Arena **slot = _memory_scratch_pool;
    for (
    u8 index = 0; index < MEMORY_ARENA_SCRATCH_POOL_COUNT; index++, slot += 1)
    {
      *slot = memory_arena_reserve_default();
    }
  }

  //- rhjr: creating non-conflicting arena
  ArenaScratch result = {0};
  Arena **slot = _memory_scratch_pool;

  for (
    u8 index = 0; index < MEMORY_ARENA_SCRATCH_POOL_COUNT; index++, slot += 1)
  {
    Arena **conflict_ptr = conflicting_arena;
    b8 is_non_conflict = true;

    for (u32 jndex = 0; jndex < count; jndex++, conflict_ptr += 1)
    {
      if (*slot == *conflict_ptr)
      {
        is_non_conflict = false;
        break;
      }
      
    }

    if (is_non_conflict)
    {
      result = memory_begin_temp(*slot);
      break;
    }

  }

  return result;
  
}

// internal_memory.c ends here.
