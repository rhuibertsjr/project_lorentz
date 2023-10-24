/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#include "base/lorentz_base.h"
#include "platform/lorentz_platform.h"

#include "base/lorentz_base.c"
#include "platform/lorentz_platform.c"

int main(int argc, char *argv[])
{
  lrtz_os_init(argc, argv);

  Arena *permanent_storage = memory_arena_reserve_default();

  u64 *ptr = arena_alloc(permanent_storage, u64, 2);
  *ptr++ = UINT64_MAX ;
  *ptr++ = 100;

  ptr = arena_alloc(permanent_storage, u64, 2);
  *ptr++ = UINT64_MAX;
  *ptr++ = 100;

  return 0;
}
