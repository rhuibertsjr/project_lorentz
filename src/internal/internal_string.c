/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

//- rhjr: constructors

internal u8str 
  u8str_init(u8 *cstring, u64 length)
{
  u8str result = { cstring, length };
	return result; 
}

internal u16str 
  u16str_init(u16 *cstring, u64 length)
{
  u16str result = { cstring, length };
	return result; 
}

// internal_string.c ends here
