/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

thread_local Arena _memory_scratch_pool[MEMORY_ARENA_SCRATCH_POOL_COUNT];

internal Arena *
  memory_get_scratch_pool(Arena *conflicting_arena)
{
  LRTZ_ASSERT(false);

  Arena *result = 0;

  return result;
  
}

