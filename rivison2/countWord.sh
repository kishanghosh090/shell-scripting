#!/bin/bash

read -p "enter a text" text
read -p "enter a word" word

text=${text,,}
word=${word,,}

count=0

for w in ${text}
do
    if [[ $w == $word ]]
    then
        (( count++ ))
    fi
done

echo $count