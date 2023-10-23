/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#include "base/lorentz_base.h"
#include "base/lorentz_base.c"

#include "platform/lorentz_platform.h"
#include "platform/lorentz_platform.c"

int main(int argc, char *argv[])
{
  lrtz_os_init(argc, argv);

  Arena *arena = memory_arena_reserve_default();

  ArenaScratch scratch = memory_get_scratch_pool(0, 0);

  memory_end_scratch(&scratch);

  return 0;
}
