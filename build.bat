@echo off

if not exist "P:\lorentz\bin\" mkdir "P:\lorentz\bin\"

pushd "P:\lorentz\bin\"

cl -Zi -DLRTZ_ENABLE_ASSERT=1 ..\src\main.c user32.lib kernel32.lib gdi32.lib 

popd "P:\lorentz\bin\"
