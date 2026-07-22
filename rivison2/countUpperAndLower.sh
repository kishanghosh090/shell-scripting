#!/bin/bash

echo "Enter a string:"
read str

upper=0
lower=0
digit=0

for((i=0;i<${#str};i++))
do
    ch=${str:$i:1}

    if [[ $ch == [A-Z] ]]
    then
        upper=$((upper+1))

    elif [[ $ch == [a-z] ]]
    then
        lower=$((lower+1))

    elif [[ $ch == [0-9] ]]
    then
        digit=$((digit+1))
    fi
done

echo "Uppercase = $upper"
echo "Lowercase = $lower"
echo "Digits = $digit"