#!/bin/bash

if (( 10 > 5 ))
then
    echo "10"
else 
    echo "5"
fi    


# case


case a in
    a) date;;
    b) ls;;
    *) echo "not match!!"
esac    