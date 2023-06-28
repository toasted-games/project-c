@echo off

cd ..

if not exist build echo "Build directory does not exist. Please run scripts\build.bat first." && exit /b 1

cd build

if not exist Debug echo "Debug directory does not exist. Please run scripts\build.bat first." && exit /b 1

cd Debug

REM find executable
for /f "delims=" %%i in ('dir /b /s *.exe') do set executable=%%i

REM run executable
call %executable%

cd ../../scripts

REM Path: scripts\test.bat