#!/bin/bash

echo "-- [ UXCTL BUILD SCRIPT ] --"
mkdir bin &
gcc main.c -o bin/uxctl 

case $1 in
  "--install" | "-i")
    echo "prod build strated..."
    if [[ $(whoami) != "root" ]]; then
      echo "You are not root, trying run commands with sudo..."
      break
    fi
    mkdir /usr/local/etc/uxctl & 
    cp ./bin/uxctl /usr/bin
    cp -r assets/ /usr/local/etc/uxctl
  ;;
  "-h" | "--help")
    printf "\n\n [ Flags ] \n\n   --install -i # Build and install\n\n"
  ;;
esac
printf "\nProgramm was built successful\n$1\n"
