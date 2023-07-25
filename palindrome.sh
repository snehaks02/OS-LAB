#!/bin/bash

echo "Enter the string:"
read string

rev=""

len=${#string}
for ((i = len - 1; i >= 0; i--))
do
    rev="$rev${string:$i:1}"
done

echo $rev

if [ "$string" = "$rev" ]
then
    echo "String is a palindrome."
else
    echo "String is not a palindrome."
fi
