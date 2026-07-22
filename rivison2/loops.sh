#!/bin/bash

# chai="alychi,ginger,masala"
# IFS=',' read -r -a tea <<< "$chai"

# echo ${tea[*]}

# for i in "${tea[*]}"
# do
#     echo $i
# done    


# arr=(alychi 90 3 milk water alychi somesuger)
# i=0
# while [[ i -lt ${#arr[*]} ]]
# do
#     echo "${arr[i]}"
#     let i++
# done
# echo ${#arr[*]}




s1="kishan"
s2=""

for (( i=0;i<${#s1};i++ ))
do
    idx=$(( ${#s1} - 1 - $i  ))
    s2+=${s1:idx:1}
done

echo $s2