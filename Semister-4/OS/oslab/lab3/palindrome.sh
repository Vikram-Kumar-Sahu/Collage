#!/bin/bash
read -p "enter a string:" str
rev_str=$(echo "$str" |rev)
if  [ "$str" = "$rev_str" ]; then
	echo "the string '$str' is a palindrome."
else
	echo "the string '$str' is not palindrome."
fi
