#KISHAN RANA GHOSH; 21.sh; 19/07/2026
#!/bin/bash

echo "Enter a string:"
read str

count=0

for ((i=0; i<${#str}; i++))
do
    ch=${str:$i:1}

    case $ch in
        [aeiouAEIOU])
            count=$((count + 1))
            ;;
    esac
done

echo "Number of vowels = $count"