#!/bin/bash
read -p "entwe number:" num

s=0
n=$num

while [ $n -gt 0 ]
do
	r=$((n%10))
	s=$((s*10+r))
	n=$((n/10))
done
echo "reverced number : $s"
