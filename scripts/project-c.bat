@echo off


:menu

CLS

echo.
echo =====================================
echo  Project C builder and runner script 
echo =====================================
echo.

echo ===================
echo  Choose an option:          
echo  1. Build               
echo  2. Build and run                
echo  3. Clean               
echo  4. Exit        
echo ===================
echo.

SET /P input=Select option then press ENTER:

echo.

if "%input%"=="1" goto build
if "%input%"=="2" goto run
if "%input%"=="3" goto clean
if "%input%"=="4" goto exit



goto menu

:build
echo Building...
call ./build.bat
if %ERRORLEVEL% NEQ 0 goto menu
echo.
echo ===================
echo  Build successful!
echo ===================
timeout 2 >nul
goto menu

:run
echo.
echo ===================
echo  Program output:
echo ===================
echo.
call ./start.bat
if %ERRORLEVEL% NEQ 0 goto menu
echo.
echo ==============================
echo  Program exited successfully!
echo ==============================
timeout 5 >nul
goto menu

:clean
echo Cleaning...
call ./clean.bat
if %ERRORLEVEL% NEQ 0 goto menu
echo.
echo ===================
echo  Clean successful!
echo ===================
timeout 2 >nul
goto menu

:exit
echo.
