#!/bin/bash
a=$(date)
echo $a
current_date=$(date "+%a %b %d %H:%M:%S %Z %Y")

day=$(date "+%d")
month=$(date "+%m")
year=$(date "+%Y")
time=$(date "+%I:%M:%S %p")
echo "$day/$month/$year/$time"
