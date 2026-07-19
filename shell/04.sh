#KISHAN RANA GHOSH; 04.sh; 19/07/2026
#!/bin/bash

read -p "Enter a number: " num


original=$num
sum=0

while [ $num -gt 0 ]
do
    digit=$((num % 10))
    sum=$((sum + digit * digit * digit))
    num=$((num / 10))
done

case $sum in
    $original)
        echo "$original is an Armstrong number."
        ;;
    *)
        echo "$original is not an Armstrong number."
        ;;
esac