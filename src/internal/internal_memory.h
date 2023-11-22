/* CopyrGight (C) 2023 René Huiberts 
   All rights reserved. */

#pragma once

#ifndef INTERNAL_MEMORY_H
#define INTERNAL_MEMORY_H

//= rhjr: arena allocator

#define MEMORY_ARENA_SCRATCH_POOL_COUNT  0x4

#define MEMORY_ARENA_DEFAULT_COMMIT_SIZE mb(1)
#define MEMORY_ARENA_DEFAULT_ALIGNMENT sizeof(void*)

//- rhjr: arena types

typedef struct Arena Arena;
struct Arena
{
  u64 *memory;
  u64 offset;
  u64 size; 
};

typedef struct ArenaScratch ArenaScratch; 
struct ArenaScratch
{
  Arena *arena;
  u64 offset;
};

//- rhjr: arena api

// rhjr: constructor
internal Arena * memory_arena_reserve (u64 size);

internal Arena * memory_arena_reserve_default ();

// rhjr: allocator
internal void * memory_arena_alloc (Arena *arena, u64 size);
#define arena_alloc(arena, type, amount)                                       \
  memory_arena_alloc((arena), sizeof(type) * (amount))

// rhjr: release
internal void memory_arena_free (Arena *arena);

// rhjr: helpers
internal u64 memory_align_forward (u64 ptr, u64 align);

// rhjr: temporary
internal ArenaScratch memory_begin_temp (Arena *arena);
internal void memory_end_temp (ArenaScratch *arena);

//= rhjr: scratch memory

internal ArenaScratch
  memory_get_scratch_pool(Arena **conflicting_arena, u32 count);
#define memory_end_scratch(scratch) memory_end_temp(scratch)

#endif // INTERNAL_MEMORY_H
// internal_memory.h ends here.
