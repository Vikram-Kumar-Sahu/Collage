#!/bin/bash
a=$(date)
echo $a
current_date=$(date "+%a %b %d %H:%M:%S %Z %Y")

day=$(date "+%d")
month=$(date "+%m")
year=$(date "+%Y")
time=$(date "+%I:%M:%S %p)
echo "$day/$month/$year/$time"





<<comment

# Execute both ps commands and filter for processes with PPID=2
# Extract only the headers from ps -ux for formatting

headers=$(ps -ux | head -1)

# Filter processes using ps -ef and format using ps -ux
echo "$headers"
ps -ef | awk '$3 == 2 {print $2}' | while read pid; do
  ps -ux | grep "^\S\+\s\+$pid " | grep -v "grep"
done



for p in {2..100}
do 
        c=0
	for ((i=1; i<=p ;i++))
	do
		a=$((p%i))
		if [[ $a -eq 0 ]]
		then
			((c++))
		fi
	done
	if [[ c -eq 2 ]]
	then 
		echo "$p"
	fi
	
done























read -p "enter the first number " a
read -p "enter the second number " b
read -p "enter the third number " c
if [[ $a -gt $b && $a -gt $c ]]
then
	echo "$a is the greatest num"
elif [[ $b -gt $a && $b -gt $c ]]
then
	echo "$b is the greatest num"
elif [[ $c -gt $a && $c -gt $b ]]
then
	echo "$c is the greatest num"
else
	echo "the three nums are equal"
fi




read -p "enter year " y
a=$((y % 4))
b=$((y % 100))
c=$((y % 400))
if [[ ($a -eq 0 && $b -eq 0) || $c -eq 0 ]]
then
	echo "$y is a leap year"
else
	echo "$y is not a leap year"
fi
comment
