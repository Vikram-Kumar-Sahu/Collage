#!/bin/bash
#array
myArray=( 1 20 30.5 "Hey Buddy!")

echo "Value in 3r index is ${myArray[3]}"
echo "values in array are ${myArray[*]}"
echo "Values from index 2-3 ${myArray[*]:2:2}"


#updating our array with new values
myArray+=( New 30 40 )
echo "Values of new array are ${myArray[*]}"
