#!/bin/bash

# Use First Argument As Working Directory
WDIR="$1"
cd "$WDIR"

if [ "$2" -eq 1 ] ; then
    echo "TODO Objective 1"
elif [ "$2" -eq 2 ] ; then
    echo "TODO Objective 2"
fi

echo "Finished"
