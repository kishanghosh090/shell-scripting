#!/bin/bash

# greet_user() {
#     echo "$@"
#     echo "$0"
# }
# var=$@
# newVar=$(hostname)
# echo "$newVar"
# greet_user $var

# bash
# <<comments
# hello
# is multi line
# comment
# comments

#zsh
: << 'COMMENT'

hello from zsh multi line comments
COMMENT
# myvar=(1 23 34 kishan)
var=$(cat varss.sh)
echo "$var"