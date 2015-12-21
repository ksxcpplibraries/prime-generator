
@echo off
cd /d "%~dp0"
cd ..
set include=../../include
set prime=../../prime
echo Compiling...
g++ -std=c++14 -o ./.out/main.exe prime-generator.cpp
if %errorlevel% neq 0 goto failed
echo Compiling Successfull.
goto final
:failed
echo Compiling failed.
:final
echo Exit code: %errorlevel%.
