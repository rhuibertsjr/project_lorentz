/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#ifndef LORENTZ_OS_API_H
#define LORENTZ_OS_API_H

//- rhjr: os initialize

internal void lrtz_os_init(int argc, char **argv);

//- rhjr: os memory

internal void * platform_memory_reserve  (u64 size);
internal b8     platform_memory_commit   (void *ptr, u64 size);

internal void   platform_memory_decommit (void *ptr, u64 size);
internal void   platform_memory_release  (void *ptr, u64 size);

#endif // LORENTZ_OS_API_H 
// os_api.h ends here.

