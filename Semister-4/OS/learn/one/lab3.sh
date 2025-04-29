#!/bin/bash

echo "home directory: $HOME"
echo "bash version: $BASH_VERSION"
echo "Host Name: $(hostname)"
echo "Current Directory: $(pwd)"




read -p "enter a number" n
k=$n
b=0
while [ $n -gt 0 ]
do 
	a=$((n%10))
	b=$((b*10+a))
	n=$((n/10))
done
echo "$b"
if [[ $k -eq $b ]]
then
	echo "palindrome"
else
	echo "non palindrome"
fi

