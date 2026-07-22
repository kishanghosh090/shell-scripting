#!/bin/bash

declare -A word1
declare -A word2

read -p "Enter first string " str1
read -p "Enter second string " str2


for (( i=0;i<${#str1};i++ ))
do
    (( word1[${str1:i:1}]++ ))
done


for (( i=0;i<${#str2};i++ ))
do
    (( word2[${str2:i:1}]++ ))
done

echo ${!word1[@]}
echo ${word2[@]}
