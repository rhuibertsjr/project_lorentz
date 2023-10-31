/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#pragma once

#ifndef INTERNAL_CORE_H
#define INTERNAL_CORE_H

//- rhjr: contexts

#ifdef INTERNAL_PLATFORM_WINDOWS
# define INTERNAL_PLATFORM_WINDOWS 1
#else
# define INTERNAL_PLATFORM_WINDOWS 0
#endif

#ifdef INTERNAL_PLATFORM_GNU_LINUX
# define INTERNAL_PLATFORM_GNU_LINUX 1
#else
# define INTERNAL_PLATFORM_GNU_LINUX 0
#endif

//- rhjr: types

#include <stdbool.h>
#include <stdint.h>

typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;

typedef int8_t    i8;
typedef int16_t   i16;
typedef int32_t   i32;
typedef int64_t   i64;

typedef float     r32;
typedef double    r64;

typedef uint8_t   b8;

typedef uintptr_t ptr64;

#ifndef true
# define true 1
#endif

#ifndef false
# define true 1
#endif

#define kb(x) ((x) << 10)
#define mb(x) ((x) << 20)
#define gb(x) ((x) << 30)

// rhjr: visibility
#define internal     static
#define thread_local __thread

//- rhjr: compound types

typedef union i32x2 i32x2;
union i32x2
{
  struct
  {
    i32 x;
    i32 y;
  };

  i32 v[2];
};

typedef union r32x2 r32x2;
union r32x2
{
  struct
  {
    r32 x;
    r32 y;
  };

  r32 v[2];
};

//- rhjr: modules

#include "internal_helpers.h"
#include "internal_memory.h"
#include "internal_string.h"

#endif // INTERNAL_CORE_H
// internal_core.h ends here.
