@echo off

if not exist "P:\lorentz\bin\" mkdir "P:\lorentz\bin\"

set CC=gcc

rem set CLAGS= -Werror
set CFLAGS=-std=c11 -Wall -Wextra -g -c -Wno-unused-function
set LDFLAGS=-luser32 -lkernel32 -lgdi32

set OPTS=-DINTERNAL_ASSERT=1 -DINTERNAL_DEBUG_ASSERT=1 -DINTERNAL_LOGGING=1 ^
         -DINTERNAL_PLATFORM_WINDOWS 

pushd "P:\lorentz\bin\"

%CC% %CFLAGS% %OPTS% ..\src\lorentz.c -o lorentz.exe %LDFLAGS%

popd "P:\lorentz\bin\"
