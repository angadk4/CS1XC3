#!/bin/bash

# Use First Argument As Working Directory
WDIR="$1"
cd "$WDIR"

if [ -z "$3" ]; then
    filename="file1.txt"
else
    filename="$3"
fi

if [ "$2" -eq 1 ] ; then
    if [ ! -f "$filename" ] ; then
        echo "$USER" > "$filename"
    fi
elif [ "$2" -eq 2 ] ; then
    if [ -f "$filename" ] ; then
        if [ ! -d "backup" ] ; then
            mkdir "backup"
        fi
        cp "$filename" "backup/"
    fi
elif [ "$2" -eq 3 ] ; then
    if [ -f "backup/$filename" ] ; then
        cp "backup/$filename" "$filename"
        rm "backup/$filename"
    fi
fi

if [ "$#" -gt 3 ]; then
    echo "${@:4}" > excess.txt
fi

echo "Finished"

