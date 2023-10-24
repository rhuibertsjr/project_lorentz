/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#ifndef LORENTZ_BASE_LOG_H
#define LORENTZ_BASE_LOG_H

typedef enum LrtzLogType LrtzLogType;
enum LrtzLogType
{
  ERROR = 0x00,
  WARNING,
  INFO
};

typedef enum LrtzLogTag LrtzLogTag;
enum LrtzLogTag
{
  TAG_NONE = 0x00,
  TAG_ASSERT,
  TAG_UNIMPLEMENTED,
  TAG_PLATFORM,
  TAG_GRAPHICS
};

#define LRTZ_LOG_MAX_MESSAGE_LENGTH 1024

internal void lrtz_log(LrtzLogTag tag, LrtzLogType type, String8 format, ...);

//- rhjr: assertions

#include <stdio.h>

#if !defined(AssertBreak)
# define ASSERT_BREAK() (*(volatile int*)0 = 0)
#endif

#if LRTZ_ENABLE_ASSERT
#  define LRTZ_ASSERT(c)                                                       \
LRTZ_STATEMENT( if (!(c)) { lrtz_log(TAG_ASSERT, ERROR,                        \
  str8_lit("\"%s\" at %s::%d"), #c, __FILE__, __LINE__); fflush(stdout);       \
  ASSERT_BREAK(); } )
#else
#  define LRTZ_ASSERT(c)
#endif

#define UNIMPLEMENTED(msg)                                                     \
  LRTZ_STATEMENT(lrtz_log(TAG_UNIMPLEMENTED, WARNING, str8_lit("%s"), #msg);)

#endif // LORENTZ_BASE_LOG_H
// log.h ends here
