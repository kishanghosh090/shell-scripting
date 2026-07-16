#!/bin/bash

myArr=( 11 3 34 344 kishan )

# echo "${myArr[0]}"
# echo "$myArr"
# echo "${myArr[1]}"
# echo "${myArr[2]}"
# echo "${#myArr[*]}"
shell=$SHELL
echo "${myArr[*]:1} $shell"

myArr+=( 5 dsug 5 dsdg )

echo "${myArr[*]}"
