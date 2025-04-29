#!/bin/bash

#getting values from a file names.txt

FILE="/home/kiit/learn/one/name.txt"
for name in $(cat $FILE)
do
	echo "name is $name"
done
