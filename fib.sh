#!/bin/bash

echo "Enter the value n:"
read n

a=0
b=1
count=2

echo "Fibonacci series:"
echo $a
echo $b

while [ $count -le $n ]
do
    fib=$(( $a + $b ))
    a=$b
    b=$fib
    echo $fib
    count=$(( $count + 1 ))
done
