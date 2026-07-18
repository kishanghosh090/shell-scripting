myVar="hello from kishan"

echo "$myVar"
len=${#myVar}
upper=${myVar^^}
lower=${myVar,,}
replace=${myVar/kishan/hitesh}
echo "$replace"

slice=${myVar:1:3}
echo "$slice"
