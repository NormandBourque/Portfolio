#!/bin/sh

echo "What month do you want to search for Geeky Holidays in?"
read month
month_date=$(date +"%d")
echo "$month_date"
while [ $month_date -le "31" ]
	do
		awk "/"$month_date-$month"/{print}" GeekyHolidays.txt
		month_date=`expr $month_date + 1`
	done
