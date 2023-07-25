#!/bin/Sh
echo "enter num1"
read n1

if(( n1 %2 == 0 ));then
    echo "entered number $n1 is even"
else
    echo "entered number $n1 is odd"
fi
