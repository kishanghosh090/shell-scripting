#!/bin/bash

# Check if an argument is provided
if [ $# -ne 1 ]
then
    echo "Usage: $0 <string>"
    exit 1
fi

str=$(echo "$1" | tr '[:upper:]' '[:lower:]')
rev=""

len=${#str}

for ((i=len-1; i>=0; i--))
do
    rev="$rev${str:$i:1}"
done

if [ "$str" = "$rev" ]
then
    echo "\"$1\" is a palindrome."
else
    echo "\"$1\" is not a palindrome."
fi