#!/bin/bash

read -p "Enter the number of terms: " n

a=0
b=1
count=1

echo "Fibonacci Series: "

while [ $count -le $n ]
do
    echo -n "$a "

    c=$((a + b))
    a=$b
    b=$c

    count=$((count + 1))
done

echo