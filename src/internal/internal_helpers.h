/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#pragma once

#ifndef INTERNAL_HELPERS_H
#define INTERNAL_HELPERS_H

//= rhjr: helpers

#define STATEMENT(S) do { S } while(0)
#define UNUSED(x) (void)(x) 

//= rhjr: application logs

#include <stdarg.h>

typedef enum internal_log_type internal_log_type;
enum internal_log_type
{
  ERROR = 0x00,
  WARNING,
  INFO
};

typedef enum internal_log_tag internal_log_tag;
enum internal_log_tag
{
  TAG_NONE = 0x00,
  TAG_ASSERT,
  TAG_PLATFORM
};

const char *_internal_log_table_type[] = {
  "ERROR", "WARNING", "INFO"};

const char *_internal_log_table_tag[] = {
  [TAG_NONE]     = "",
  [TAG_ASSERT]   = "ASSERT FAILED",
  [TAG_PLATFORM] = "Platform"
};

internal void
_internal_stdout_log(
  internal_log_tag tag, internal_log_type type, const char* format, ...);

//- rhjr: log macro

#ifdef INTERNAL_LOGGING
# define log(tag, type, message, ...)                                          \
  STATEMENT(_internal_stdout_log(tag, type, message, ##__VA_ARGS__);)
#else
# define log(tag, type, message, ...)
#endif

//= rhjr: abort & assertion

internal _Noreturn ptr64
_internal_assert (
  const char* condition, const char* file, u32 line, const char *message, ...);

//- rhjr: assert macro

#ifdef INTERNAL_ASSERT
# define assert(condition, ...)                                                \
    STATEMENT( if(!(condition)) {                                              \
      _internal_assert(#condition, __FILE__, __LINE__, ##__VA_ARGS__);})
#else
# define assert(condition, ...)
#endif

#endif // INTERNAL_HELPERS_H
// internal_helpers.h ends here.
