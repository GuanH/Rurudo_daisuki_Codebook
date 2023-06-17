@echo off
:loop
    echo %%x
    python gen.py > input
    ./ac.exe < input > ac.out
    ./wa.exe < input > wa.out
    fc ac.out wa.out
if not errorlevel 1 goto loop