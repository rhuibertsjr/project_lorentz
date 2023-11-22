/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#pragma once

#ifndef INTERNAL_STRING_H
#define INTERNAL_STRING_H

//= rhjr string types

typedef struct u8str u8str;
struct u8str
{
  u8 *content;
  u64 length; 
};

typedef struct u16str u16str;
struct u16str
{
  u16 *content;
  u64 length; 
};

//= rhjr: constructors

internal u8str u8str_init(u8 *string, u64 length);
#define u8str_lit(string) u8str_init((u8str*)(string), sizeof(string) - 1)

internal u16str u16str_init(u16 *string, u64 length);
#define u16str_lit(string) u16str_init((u16str*)(string), sizeof(string) - 1)

#endif // INTERNAL_STRING_H
// internal_string.h ends here.
