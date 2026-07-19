#KISHAN RANA GHOSH; 14.sh; 19/07/2026
#!/bin/bash

echo "Enter first number:"
read num1

echo "Enter second number:"
read num2

echo "----- Calculator Menu -----"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "---------------------------"

echo "Enter your choice (1-4):"
read choice

case $choice in
    1)
        result=$((num1 + num2))
        echo "Result = $result"
        ;;
    2)
        result=$((num1 - num2))
        echo "Result = $result"
        ;;
    3)
        result=$((num1 * num2))
        echo "Result = $result"
        ;;
    4)
        if [ $num2 -eq 0 ]
        then
            echo "Division by zero is not allowed."
        else
            result=$((num1 / num2))
            echo "Result = $result"
        fi
        ;;
    *)
        echo "Invalid choice!"
        ;;
esac