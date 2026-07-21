chai="alychi,ginger,masala"
IFS=',' read -r -a tea <<< "$chai"

echo ${tea[*]}

for i in "${tea[*]}"
do
    echo $i
done    


arr=(alychi 90 3 milk water alychi somesuger)
i=0
while [[ i -lt ${#arr[*]} ]]
do
    echo "${arr[i]}"
    let i++
done
echo ${#arr[*]}