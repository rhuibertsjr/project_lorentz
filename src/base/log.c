/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#include <stdio.h>
#include <stdarg.h>

const char *lrtz_log_table_type[] = {
  "ERROR", "WARNING", "INFO"};

const char *lrtz_log_table_tag[] = {
  [TAG_NONE]     = "",
  [TAG_ASSERT]   = "ASSERT FAILED",
  [TAG_PLATFORM] = "Platform",
  [TAG_GRAPHICS] = "Graphics",
};

internal void
lrtz_log(LrtzLogTag tag, LrtzLogType type, String8 format, ...)
{
  va_list args_list;
  char message[LRTZ_LOG_MAX_MESSAGE_LENGTH];

  va_start(args_list, format);
  vsnprintf(message, LRTZ_LOG_MAX_MESSAGE_LENGTH, format.content, args_list);
  va_end(args_list);

  fprintf(stdout, "[DEBUG][%s] (%s) %s\n",
    lrtz_log_table_type[type], lrtz_log_table_tag[tag], message);

  return;
}
