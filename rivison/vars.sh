#!/bin/zsh

greet_user() {
    echo "$@"
    echo "$0"
}
var=$@

greet_user $var
