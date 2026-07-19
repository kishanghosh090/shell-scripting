#KISHAN RANA GHOSH; 01.sh; 19/07/2026
#!/bin/bash

read -p "Enter a Number: " n

if ((n < 0))
then 
    echo "Invalid number"
    exit 0
fi    

echo "Prime numbers between 2 and $n are: "
for ((i=2; i<=n; i++))
do
    prime=1

    for ((j=2; j*j<=i; j++))
    do
        if (( i % j == 0 ))
        then
            prime=0
            break
        fi
    done

    if (( prime == 1 ))
    then
        echo -n "$i "
    fi
done

