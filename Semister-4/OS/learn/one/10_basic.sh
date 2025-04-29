#!?bin/bash
read -p "Enter your marks: " marks
if [[ $marks -gt 40 ]]
then
	echo "you are pass"
else
	echo "you are fail!!"
fi
