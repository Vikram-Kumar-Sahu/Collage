#/bin/bash
if [ "$#" -lt 2 ] || [ "$#" -gt 8 ];then
	echo "Error : invalid input"
	exit 1
fi
result=$1
for((i=2;i<=$#;i++));do
	b=${!i}
	if (( result % b == 0 ));then
		result =$(( result / b ))
	elif(( result % b != 0 ))&& (( b % 5 == 0 ));then
		result=$(( result  *  b ))
	elif(( result >b ));then
		result=$((  result - b ))
	else
		result= 4(( result + b ))
	fi
done
echo "Final Result: $result"

