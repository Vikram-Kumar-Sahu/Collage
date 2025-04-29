
#!/bin/bash

declare -A myArray
myArray=( [name]=Vikram [age]=20 [city]=Kolkata)

echo "Name is ${myArray[name]}"
echo "Age is ${myArray[city]}"
