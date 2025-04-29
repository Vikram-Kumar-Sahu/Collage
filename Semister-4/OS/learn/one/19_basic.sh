#!/bin/basic
a=10

until [[ $a -eq 1 ]]
do 
echo "Value od a is $a"
let a--
done
