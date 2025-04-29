#!/bin/bash
read -p "enter a 1st file name:" file1
read -p "enter 2nd file name:" file2
read -p "enter 3rd filename" output_file

while File1= read -r line1;do
echo "text from the file: $line1"
echo $line1 >> $output_file.txt
done < $file1.txt

while File2= read -r line2; do
echo " text from the file: $line2"
echo $line2 >> $output_file.txt
done < $file2.txt

while File= read -r line; do
echo "text from the file: $line"
done < $output_file.txt
