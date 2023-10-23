/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#ifndef LORENTZ_BASE_STRING_H
#define LORENTZ_BASE_STRING_H

typedef struct String8 String8;
struct String8
{
  u8 *content;
  u64 length; 
};

//- rhjr: constructors

internal String8 str8 (u8 *string, u64 length);

#define str8_lit(string)                                                       \
  str8((u8*)(string), sizeof(string) - 1)

//- rhjr: helpers

internal String8 str8_range   (u8 *first_char, u8 *last_char);
internal String8 str8_cstring (u8 *cstring);

#endif // LORENTZ_BASE_STRING_H
// string.h ends here
