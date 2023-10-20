/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#ifndef LORENTZ_BASE_MEMORY_H
#define LORENTZ_BASE_MEMORY_H

#define MEMORY_ARENA_SCRATCH_POOL_COUNT 4

#define ARENA_DEFAULT_COMMIT_SIZE 1024

typedef struct Arena Arena;
struct Arena
{
  u64 *backing_buffer;
  u64 offset;
  u64 size; 
};

void * arena_alloc (Arena *arena, size_t size);
void   arena_free  (Arena *arena);

internal Arena * memory_get_scratch_pool(Arena *conflicting_arena);

#endif // LORENTZ_BASE_MEMORY_H
// memory.h ends here.
