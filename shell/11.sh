#!/bin/bash

sum=0
count=0
num=0

echo "Enter numbers (-1 to stop):"

until [ $num -eq -1 ]
do
    read num

    if [ $num -ne -1 ]
    then
        sum=$((sum + num))
        count=$((count + 1))
    fi
done

echo "Sum = $sum"

if [ $count -gt 0 ]
then
    avg=$((sum / count))
    echo "Average = $avg"
else
    echo "No numbers were entered."
fi