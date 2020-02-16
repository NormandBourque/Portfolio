#!/bin/sh
echo "what Month are you looking for Holidays in?"
read month
awk "/$month/{print}" GeekyHolidays.txt
# Awk is a way of searching for a pattern in a file
# GeekHolidays is the file we are searching in
# /pattern/ is what we are searching for

 
# So the line is saying hey awk, search the whole file line by line
# the specified pattern
 
#awk -F: "/$month/ {print \$1}" GeekyHolidays.txt


holiday=$(awk -F: "/$month/ {print \$1}" GeekyHolidays.txt)
echo The holidays are: "$holiday"
# This line will look for the /pattern/ but only print the 1 piece of data
# So in this case the Holiday rather then the whole line
# This will also assign the results to a variable called holiday
# -F: makes awk use : as the delineator instead of spaces
