/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

internal String8
  str8(u8 *cstring, u64 length)
{
  String8 result = { cstring, length };
	return result; 
}

internal String8
  str8_range(u8 *first_char, u8 *last_char)
{
  String8 result = { first_char, (u64) (last_char - first_char) };
	return result; 
}

internal String8
  str8_cstring(u8 *cstring)
{
	u8 *ptr = cstring;
  for(; *ptr != 0; ptr += 1);
	return str8_range(cstring, ptr);
}
