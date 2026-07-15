#!/bin/bash

# Check if three arguments are provided
if [ $# -ne 3 ]
then
    echo "Usage: $0 num1 num2 num3"
    exit 1
fi

a=$1
b=$2
c=$3

if [ $a -le $b ] && [ $a -le $c ]
then
    min=$a
elif [ $b -le $a ] && [ $b -le $c ]
then
    min=$b
else
    min=$c
fi

case $min in
    $a)
        echo "Minimum number is: $a"
        ;;
    $b)
        echo "Minimum number is: $b"
        ;;
    $c)
        echo "Minimum number is: $c"
        ;;
esac