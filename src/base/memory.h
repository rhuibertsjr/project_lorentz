/* CopyrGight (C) 2023 René Huiberts 
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
#define MEMORY_ARENA_DEFAULT_ALIGNMENT sizeof(void*)

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
Arena * memory_arena_reserve (u64 size);

Arena * memory_arena_reserve_default ();

// rhjr: allocator
void * memory_arena_alloc (Arena *arena, u64 size);
#define arena_alloc(arena, type, amount)                                       \
  memory_arena_alloc((arena), sizeof(type) * (amount))

// rhjr: release
void memory_arena_free (Arena *arena);

// rhjr: helpers
u64 memory_align_forward (u64 ptr, u64 align);
#define IS_POWER_OF_2(x) (((uptr64)x & (((uptr64) x) -1 )) == 0)

// rhjr: temporary
ArenaScratch memory_begin_temp (Arena *arena);
void memory_end_temp (ArenaScratch *arena);

//- rhjr: scratch memory

ArenaScratch memory_get_scratch_pool(Arena **conflicting_arena, u32 count);
#define memory_end_scratch(scratch) memory_end_temp(scratch)

#endif // LORENTZ_BASE_MEMORY_H
// memory.h ends here.
