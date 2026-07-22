#!/bin/bash

echo $UID
echo $RANDOM
something=12
let something++ 
(( something++ ))
exp=`expr ${something} + 1`
cat hello.txt
exp=`expr ${RANDOM} + 1`
echo $exp