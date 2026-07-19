#KISHAN RANA GHOSH; 19.sh; 19/07/2026
#!/bin/bash

echo "Enter the file name:"
read file

if [ ! -f "$file" ]
then
    echo "File does not exist."
    exit 1
fi

echo "Enter the word to search:"
read word

echo "Lines containing '$word':"
grep "$word" "$file"