/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

//- rhjr: lorentz application entry

internal void
platform_os_init(int argc, char **argv)
{
  INTERNAL_UNUSED(argc);
  INTERNAL_UNUSED(argv);

  log(TAG_PLATFORM, INFO, "Initializing win32 platform.");
}

//- rhjr: lorentz application memory

internal void *
platform_memory_reserve (u64 size)
{
  return VirtualAlloc(0, size, MEM_RESERVE, PAGE_READWRITE);
}

internal b8
platform_memory_commit (void *ptr, u64 size)
{
  return (VirtualAlloc(ptr, size, MEM_COMMIT, PAGE_READWRITE) != 0);
}

internal void
platform_memory_decommit (void *ptr, u64 size)
{
  VirtualFree(ptr, size, MEM_DECOMMIT);
}

internal void
platform_memory_release (void *ptr, u64 size)
{
  VirtualFree(ptr, size, MEM_RELEASE);
}

// win32_platform.c ends here.
