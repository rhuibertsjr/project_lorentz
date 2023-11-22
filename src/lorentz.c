/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#include "internal/internal_core.h"
#include "platform/platform_os.h"

#include "internal/internal_core.c"
#include "platform/platform_os.c"

int main(int argc, char *argv[])
{
  platform_os_init(argc, argv);
  return 0;
}

// lorentz.c ends here.
