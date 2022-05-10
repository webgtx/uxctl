#!/bin/sh
echo -- [ UXCTL BUILD SCRIPT ] --
mkdir bin & 
gcc main.c -o bin/uxctl
if [[ $(whoami) != "root" ]]; then
  echo "You are not root, trying run commands with sudo..."
  sudo mkdir /usr/local/etc/uxctl
  sudo cp -r assets/ /usr/local/etc/uxctl
fi
mkdir /usr/local/etc/uxctl
cp -r assets/ /usr/local/etc/uxctl
printf "\nProgramm was built successful\n"
