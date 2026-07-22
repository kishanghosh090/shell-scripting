#!/bin/bash

read -p "Enter a text which you want to know how many vowels have? " text

# output=$(echo $text | grep -o -i [aeiou] | wc -l)
# echo $output
# conso=$(( ${#text} - $output ))
# echo $conso

count=0

for (( i=0;i<${#text};i++ ))
do
    if [[ ${text:i:1} == [aeiou] ]]
    then
        (( count++ ))
    fi    
done

echo $count
