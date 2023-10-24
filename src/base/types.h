/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#ifndef LORENTZ_TYPES_H
#define LORENTZ_TYPES_H

//- rhjr: contexts

#if defined(_WIN32)
#  define LRTZ_PLATFORM_WINDOWS 1
#elif defined(__gnu_linux__)
#  define LRTZ_PLATFORM_GNU_LINUX 1
#elif defined(__APPLE__) && defined(__MACH__)
#  define LRTZ_PLATFORM_DARWIN 1
#else
#  error missing OS detection.
# endif

#if defined(_M_AMD64)
#  define LRTZ_ARCH_X64 1
#elif defined(_M_I86)
#  define LRTZ_ARCH_X86 1
#else
#  error missing ARCH detection.
# endif

// rhjr: nullify missing context macros
#if !defined(LRTZ_PLATFORM_WINDOWS)
#  define LRTZ_PLATFORM_WINDOWS 0
#endif
#if !defined(LRTZ_PLATFORM_GNU_LINUX)
#  define LRTZ_PLATFORM_GNU_LINUX 0
#endif
#if !defined(LRTZ_PLATFORM_DARWIN)
#  define LRTZ_PLATFORM_DARWIN 0
#endif
#if !defined(LRTZ_ARCH_X64)
# define LRTZ_ARCH_X64 0
#endif
#if !defined(LRTZ_ARCH_X86)
# define LRTZ_ARCH_X86 0
#endif
#if !defined(LRTZ_ARCH_ARM)
# define LRTZ_ARCH_ARM 0
#endif

#if !defined(LRTZ_ENABLE_ASSERT)
#  define LRTZ_ENABLE_ASSERT 0
#endif

//- rhjr: helpers macros types

#define internal     static
#define thread_local __declspec(thread)

//- rhjr: helpers macros functions

#define LRTZ_STATEMENT(S) do{ S } while(0)

#define KB(x) ((x) << 10)
#define MB(x) ((x) << 20)
#define GB(x) ((x) << 30)
#define TB(x) ((x) << 40)

//- rhjr: common types

#include <stdint.h>

typedef uintptr_t uptr64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;

typedef float    r32;
typedef double   r64;

typedef uint8_t  b8;

#define true  1
#define false 0

//- rhjr: compound types

union v2i32
{
  struct
  {
    i32 x;
    i32 y;
  };

  i32 v[2];
};

union v2r32
{
  struct
  {
    r32 x;
    r32 y;
  };

  r32 v[2];
};

#endif // LORENTZ_TYPES_H
