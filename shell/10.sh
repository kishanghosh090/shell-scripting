#!/bin/bash

echo "Enter a string:"
read str

echo "Enter the number of times to print:"
read n

file="output.txt"

# Clear the file if it already exists
> "$file"

for ((i=1; i<=n; i++))
do
    echo "$str"
    echo "$str" >> "$file"
done

echo "The output has been stored in $file"