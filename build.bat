@echo off

if not exist "P:\lorentz\bin\" mkdir "P:\lorentz\bin\"

pushd "P:\lorentz\bin\"

set ldflags= user32.lib kernel32.lib gdi32.lib
set opts=    -DLRTZ_ENABLE_ASSERT=1 -DENABLE_LOG=1

cl -Zi %opts% ..\src\main.c /link %ldflags% 

popd "P:\lorentz\bin\"
