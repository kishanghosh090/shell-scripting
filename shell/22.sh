#!/bin/bash

read -p "Enter first directory:" dir1

read -p "Enter second directory:" dir2

if [ ! -d "$dir1" ] || [ ! -d "$dir2" ]
then
    echo "One or both directories do not exist."
    exit 1
fi

echo "Common files in both directories:"

for file in "$dir1"/*
do
    fname=$(basename "$file")

    if [ -f "$dir2/$fname" ]
    then
        echo "$fname"
    fi
done