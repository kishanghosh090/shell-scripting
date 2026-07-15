#!/bin/bash

# Check if a binary number is provided
if [ $# -ne 1 ]
then
    echo "Usage: $0 <binary_number>"
    exit 1
fi

bin=$1
dec=0
base=1

while [ $bin -gt 0 ]
do
    rem=$((bin % 10))

    if [ $rem -ne 0 ] && [ $rem -ne 1 ]
    then
        echo "Invalid binary number!"
        exit 1
    fi

    dec=$((dec + rem * base))
    base=$((base * 2))
    bin=$((bin / 10))
done

echo "Decimal equivalent = $dec"