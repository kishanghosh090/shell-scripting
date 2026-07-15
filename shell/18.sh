#!/bin/bash

if [ $# -eq 0 ]
then
    echo "Usage: $0 file1 file2 ..."
    exit 1
fi

for file in "$@"
do
    if [ -f "$file" ]
    then
        upper=$(echo "$file" | tr '[:lower:]' '[:upper:]')

        if [ -e "$upper" ]
        then
            echo "Cannot rename $file -> $upper (target already exists)"
        else
            mv "$file" "$upper"
            echo "$file renamed to $upper"
        fi
    else
        echo "$file does not exist"
    fi
done