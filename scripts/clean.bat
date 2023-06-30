@echo off

cd ..

if exist build rmdir /s /q build
if not exist build mkdir build

cd build

cmake ..

cmake --build .

cd ../scripts

REM Path: scripts\run.bat