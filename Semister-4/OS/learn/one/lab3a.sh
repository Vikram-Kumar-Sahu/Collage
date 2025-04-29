#!/bin/bash

# Check if the number of arguments is between 1 and 8
if [ "$#" -gt 8 ]; then
    echo "Error: You can enter a maximum of 8 arguments."
    exit 1
fi

# Initialize result with the first argument
result=$1

# Loop through the remaining arguments and perform operations
for ((i = 2; i <= $#; i++)); do
    b=${!i}  # Access the ith argument
    
    if [ $((result % b)) -eq 0 ]; then
        # If the result is divisible by b, perform a/b
        result=$((result / b))
    elif [ $((result % b)) -ne 0 ] && [ $((b % 5)) -eq 0 ]; then
        # If result % b != 0 and b is divisible by 5, perform a*b
        result=$((result * b))
    elif [ $result -gt $b ]; then
        # If result > b, perform a-b
        result=$((result - b))
    else
        # Else, perform a+b
        result=$((result + b))
    fi
done

# Output the final result
echo "Final result: $result"

