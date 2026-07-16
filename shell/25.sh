#!/bin/bash

echo "Enter the file name:"
read file

if [ ! -f "$file" ]
then
    echo "File does not exist."
    exit 1
fi

timestamp=$(date +"%Y%m%d_%H%M%S")

backup_file="${file}_$timestamp"

cp "$file" "$backup_file"

echo "Backup created: $backup_file"