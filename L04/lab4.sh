#!/bin/bash

# Use First Argument As Working Directory
WDIR="$1"
cd "$WDIR"

FILE="file1.txt"
if [ -n "$3" ] ; then
    FILE="$3"
fi

if [ "$2" -eq 1 ] ; then
    if [ ! -f "$FILE" ] ; then
        echo "$USER" > "$FILE"
    fi
elif [ "$2" -eq 2 ] ; then
    if [ -f "$FILE" ] ; then
        if [ ! -d "backup" ] ; then
            mkdir backup
        fi
        cp "$FILE" backup/
    fi
elif [ "$2" -eq 3 ] ; then
    if [ -f "backup/$FILE" ] ; then
        cp "backup/$FILE" .
        rm "backup/$FILE"
    fi
fi

if [ "$#" -gt 3 ] ; then
    echo "${@:4}" > excess.txt
fi

echo "Finished"
