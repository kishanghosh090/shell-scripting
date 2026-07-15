#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage: $0 <number>"
    exit 1
fi



if [ $1 -le 0 ]
then 
    echo "Invalid Number."
    exit 0
fi  
  
num=$1
i=1

echo "Multiplication Table of $num"

while [ $i -le 10 ]
do
    echo "$num x $i = $((num * i))"
    i=$((i + 1))
done