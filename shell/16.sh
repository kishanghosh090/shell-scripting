#!/bin/bash

factorial() {
    n=$1

    if [ $n -le 1 ]
    then
        echo 1
    else
        prev=$(factorial $((n - 1)))
        echo $((n * prev))
    fi
}

echo "Enter a number:"
read num

result=$(factorial $num)

echo "Factorial of $num = $result"