# data=$(cat hello.txt)
data=kishan
word=kishan
with=hitesh
echo ${#data}
echo $data
data=${data/"$word"/"$with"}
# echo ${}
echo $data

#split
chai="alychi,ginger,masala"
IFS=',' read -r -a tea <<< "$chai"

echo ${tea[*]}

for i in "${tea[*]}"
do
    echo $i
done    