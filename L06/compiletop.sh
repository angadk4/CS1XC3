#!/bin/bash

if [ $# -eq 0 ]
  then
    echo "Please provide path to shared object library as argument"
    echo "Usage: Using rpath to run a c file coontaining a shared object file"
else
  gcc -L"$1" -Wl,-rpath="$1" -Wall -o test top.c -lLab6Part5
fi
