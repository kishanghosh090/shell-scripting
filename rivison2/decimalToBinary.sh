#!/bin/bash

function pow {
    local base=$1
    local exp=$2
    local result=1
    
    for (( i=0; i<exp; i++ ))
    do
        result=$(( result * base ))
    done
    echo $result
}

read -p "give me a binary number " number


for (( i=0; i<${#number}; i++ ))
do    
    if (( ${number:i:1} != 0 && ${number:i:1} != 1 ))
    then
        echo "invalid number"
        exit 1
    fi
done

decimal=0
len=${#number}

for (( i=0; i<len; i++ ))
do    

    if [[ ${number:i:1} -eq 1 ]]
    then
        exponent=$(( len - 1 - i ))
        
        power_val=$(pow 2 $exponent)
        decimal=$(( decimal + power_val ))
    fi
done

echo "Decimal value: $decimal"
