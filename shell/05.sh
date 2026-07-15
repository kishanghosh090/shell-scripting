#!/bin/bash

echo "Enter a symbol:"
read sym

echo "Enter the number of rows:"
read rows

for ((i=1; i<=rows; i++))
do
    # Print spaces
    j=1
    while [ $j -le $((rows - i)) ]
    do
        echo -n " "
        j=$((j + 1))
    done

    # Print symbols
    k=1
    while [ $k -le $((2 * i - 1)) ]
    do
        echo -n "$sym"
        k=$((k + 1))
    done

    echo
done