/* CopyrGight (C) 2023 Ren� Huiberts 
   All rights reserved. */

#ifndef LORENTZ_BASE_MEMORY_H
#define LORENTZ_BASE_MEMORY_H

//- rhjr: amounts

#define KB(x) ((x) << 10)
#define MB(x) ((x) << 20)
#define GB(x) ((x) << 30)

//- rhjr: arena
#define MEMORY_ARENA_SCRATCH_POOL_COUNT  0x4
#define MEMORY_ARENA_DEFAULT_COMMIT_SIZE MB(1)

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

// rhjr: constructor
Arena *      memory_arena_reserve         (u64 size);
Arena *      memory_arena_reserve_default ();

// rhjr: allocator
void  *      memory_arena_alloc           (Arena *arena, u64 size);

// rhjr: release
void         memory_arena_free            (Arena *arena);

// rhjr: temporary
ArenaScratch memory_begin_temp            (Arena *arena);
void         memory_end_temp              (ArenaScratch *arena);

//- rhjr: scratch memory

ArenaScratch memory_get_scratch_pool(Arena **conflicting_arena, u32 count);
#define memory_end_scratch(scratch) memory_end_temp(scratch)

#endif // LORENTZ_BASE_MEMORY_H
// memory.h ends here.
