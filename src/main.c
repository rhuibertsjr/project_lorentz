/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#include "base/lorentz_base.h"
#include "base/lorentz_base.c"

#include "platform/lorentz_platform.h"
#include "platform/lorentz_platform.c"

int main(int argc, char *argv[])
{
  lrtz_os_init(argc, argv);

  Arena arena = {0};
  memory_get_scratch_pool(&arena);
  
  return 0;
}
