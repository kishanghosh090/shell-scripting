#KISHAN RANA GHOSH; 03.sh; 19/07/2026
#!/bin/bash


read -p "Enter a number: " num


if [ $num -lt 0 ]
then
    echo "you entered a negetive number: $num ..."
    newNum=$((num - num * 2))
    sum=0

    until [ $newNum -eq 0 ]
    do
        digit=$((newNum % 10))
        sum=$((sum + digit))
        newNum=$((newNum / 10))
    done

    echo "Sum of digits without negetive symbol = $sum"
    echo "Sum of digits with negetive symbol = -$sum"
    
    exit 0
fi



sum=0

until [ $num -eq 0 ]
do
    digit=$((num % 10))
    sum=$((sum + digit))
    num=$((num / 10))
done

echo "Sum of digits = $sum"