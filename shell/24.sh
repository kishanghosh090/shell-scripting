#KISHAN RANA GHOSH; 24.sh; 19/07/2026
#!/bin/bash

echo "Enter the directory name:"
read dir

if [ ! -d "$dir" ]
then
    echo "Directory does not exist."
    exit 1
fi

echo "Empty files found:"

find "$dir" -type f -empty -print

find "$dir" -type f -empty -delete

echo "All empty files have been deleted."