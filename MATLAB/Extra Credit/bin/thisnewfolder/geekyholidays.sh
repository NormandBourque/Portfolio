#!/bin/sh
todays_date=$(date +"%d-%b")
echo "$todays_date"
weekday=$(date +"%A")
echo "$weekday"
case $weekday in
	Friday)
echo "Yay, Friday!";;
	Saturday)
echo "6 days until Friday.";;
	Sunday)
echo "5 days until Friday.";;
	Monday)
echo "4 days until Friday.";;
	Tuesday)
echo "3 days until Friday.";;
	Wednesday)
echo "2 days until Friday.";;
	Thursday)
echo "1 day until Friday.";;
esac

awk "/"$month_date-$month"/{print}" GeekyHolidays.txt

