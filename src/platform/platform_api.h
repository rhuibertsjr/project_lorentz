/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#pragma once

#ifndef PLATFORM_API_H
#define PLATFORM_API_H

//- rhjr: platform initialize

internal void platform_os_init(int argc, char **argv);

//- rhjr: platform memory

internal void * platform_memory_reserve  (u64 size);
internal b8     platform_memory_commit   (void *ptr, u64 size);

internal void   platform_memory_decommit (void *ptr, u64 size);
internal void   platform_memory_release  (void *ptr, u64 size);

//- rhjr: platform I/O

internal u8str platform_file_read  ();  
internal u8str platform_file_write ();  

#endif // PLATFORM_API_H 
// platform_api.h ends here.

