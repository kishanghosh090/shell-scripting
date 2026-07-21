#!/bin/bash


VAR_NAME=$(hostname)
rnd=$RANDOM
echo $rnd
echo $VAR_NAME

exp=`expr ${rnd}`

echo $exp