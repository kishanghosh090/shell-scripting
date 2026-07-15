#!/bin/bash

echo "Enter a decimal number:"
read num

binary=""

if [ $num -eq 0 ]
then
    echo "Binary equivalent = 0"
    exit 0
fi

while [ $num -gt 0 ]
do
    rem=$(( num % 2 ))
    binary="$rem$binary"
    num=$(( num / 2))
done

echo "Binary equivalent = $binary"