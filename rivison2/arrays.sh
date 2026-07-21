arr=(alychi 90 3 milk water alychi somesuger)
i=0
while [[ i -lt ${#arr[*]} ]]
do
    echo "${arr[i]}"
    let i++
done
echo ${#arr[*]}