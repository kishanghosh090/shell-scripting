#!/bin/bash

echo "Enter the base number:"
read base

echo "Enter the exponent:"
read exp

result=1
i=1

while [ $i -le $exp ]
do
    result=$((result * base))
    i=$((i + 1))
done

echo "$base raised to the power $exp = $result"