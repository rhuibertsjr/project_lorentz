/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#include <stdio.h>
#include <stdlib.h>

//= rhjr: application logs

internal void
_internal_stdout_log(
  internal_log_tag tag, internal_log_type type, const char* format, ...)
{
  char message[1024];
  va_list args_list;

  va_start(args_list, format);
  vsnprintf(message, 1024, format, args_list);
  va_end(args_list);

  fprintf(stdout, "[DEBUG][%s] (%s) %s\n",
    _internal_log_table_type[type], _internal_log_table_tag[tag], message);
}

//= rhjr: abort & assertion

internal _Noreturn ptr64
_internal_assert (
  const char* condition, const char* file, u32 line, const char *message, ...)
{
  _internal_stdout_log(
    TAG_ASSERT, ERROR, "\"%s\" at %s::%d: %s", condition, file, line, message);
  fflush(stdout);
  abort();
}

// internal_helpers.c ends here.
