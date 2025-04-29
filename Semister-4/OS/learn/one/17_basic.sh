#!/bin/bash

myArray=( 1 2 3 hello hi )

length=${#myArray[*]} # Correct assignment without spaces
  
for (( i=0; i<length; i++ ))
do
    echo "Value of array is ${myArray[$i]}"
done

