/* Copyright (C) 2023 René Huiberts 
   All rights reserved. */

#if INTERNAL_PLATFORM_WINDOWS 
# include "win32/win32_platform.c"
#endif

#if INTERNAL_PLATFORM_WINDOWS == 0 && INTERNAL_PLATFORM_GNU_LINUX == 0
# error "No platform has been specified."
#endif

// platform_os.c ends here.
