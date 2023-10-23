/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

//- rhjr: permanent storage

void* m_reserve(u64 size)
{
  void* result = malloc(size);
  return result;
}

//- rhjr: arena allocator

internal Arena *
memory_arena_reserve (u64 size)
{
  Arena *result = NULL;

  void* ptr = m_reserve(size);

  result = (Arena*) ptr;
  result->memory = (u64*) ptr + sizeof(Arena);
  result->offset = 0 + sizeof(Arena);
  result->size = size - sizeof(Arena);

  LRTZ_ASSERT(result != NULL);
  return result;
}

internal Arena *
memory_arena_reserve_default ()
{
  return memory_arena_reserve(MB(1));
}

internal void *
memory_arena_alloc (Arena *arena, u64 size)
{
  void* result = NULL;

  if (arena->offset + size <= arena->size)
  {
    result = arena->memory + arena->offset;
    arena->offset += size;

    memset(result, 0, size);
  }
  
  LRTZ_ASSERT(result != NULL);
  return result;
}

void
memory_arena_free (Arena *arena)
{
  return;
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

//- rhjr: scratch memory

thread_local Arena *_memory_scratch_pool[MEMORY_ARENA_SCRATCH_POOL_COUNT];

internal ArenaScratch
memory_get_scratch_pool(Arena **conflicting_arena, u32 count)
{
  // rhjr: initialization (first time called).
  if (_memory_scratch_pool[0] == 0)
  {
    LRTZ_ASSERT(MEMORY_ARENA_SCRATCH_POOL_COUNT <= 4); 
    Arena **slot = _memory_scratch_pool;
    for (
      u8 index = 0; index < MEMORY_ARENA_SCRATCH_POOL_COUNT; index++, slot += 1)
    {
      *slot = memory_arena_reserve_default();
    }
  }

  // rhjr: prevent conflict in scratch pool arena's
  ArenaScratch result = {0};
  Arena **slot = _memory_scratch_pool;

  for (
    u8 index = 0; index < MEMORY_ARENA_SCRATCH_POOL_COUNT; index++, slot += 1)
  {
    Arena **conflict_ptr = conflicting_arena;
    bool is_non_conflict = true;

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

