#!/bin/sh
echo -- [ UXCTL BUILD SCRIPT ] --
mkdir bin & 
time gcc main.c -o bin/uxctl
date
printf "\nProgramm was built successful\n"
