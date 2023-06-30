@echo off

cd ..

if not exist build mkdir build

cd build

cmake ..

cmake --build .

cd ../scripts
