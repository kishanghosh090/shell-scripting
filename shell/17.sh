#KISHAN RANA GHOSH; 17.sh; 19/07/2026
#!/bin/bash

echo "Enter the first file name:"
read file1

echo "Enter the second file name:"
read file2

if diff "$file1" "$file2" > /dev/null 2> err.log
then
    echo "The files are identical."

    echo "Do you want to delete $file2? (y/n)"
    read choice

    case $choice in
        y|Y)
            rm "$file2"
            echo "$file2 has been deleted."
            ;;
        n|N)
            echo "File not deleted."
            ;;
        *)
            echo "Invalid choice."
            ;;
    esac
else
    echo "The files are different."
fi