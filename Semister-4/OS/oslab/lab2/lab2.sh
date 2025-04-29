#!/bin/bash

read -p "Enter year: " year

if (( year % 4 == 0 && year % 100 != 0 )) || (( year % 400 == 0 )); then
    echo "is a leap year "$year.
else
    echo "is not a leap year" $year
fi


read -p "Enter three number: " n1 n2 n3

if ((n1 > n2 && n1 > n3)); then
	echo "the greatest number is: $n1"
elif (( n2 > n1 && n2 > n3)); then
	echo "the greatest number is: $n2"
else
	echo "the greatest number is: $n3"
fi


echo "Prime numbers between 1 and 100 are:"

for ((num=2; num<=100; num++))
do
  prime=1  

  for ((i=2; i<num; i++))
  do
    if ((num % i == 0)); then
      prime=0  
      break
    fi
  done
  if ((prime == 1)); then
    echo -n "$num "
  fi
done

echo


# Get the current date and time in the format "Thu Jan 2 14:21:54 IST 2014"
current_date=$(date)

# Extract components from the current date using the `date` command directly
formatted_date=$(date +"%d/%m/%Y/%I:%M:%S %p")

# Display the formatted date
echo "$formatted_date"

