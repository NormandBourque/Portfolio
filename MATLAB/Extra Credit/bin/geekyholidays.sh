#!/bin/sh
#shebang line
todays_date=$(date +"%d-%b")
#assigning a variable to current month and day that's being sent from the server
echo "$todays_date"
#printing the output send from the server of the current month and day
weekday=$(date +"%A")
#assigning the weekday sent from the server to a variable
echo "$weekday"
#printing the line of the weekday to the command line
echo "Today is $weekday $todays_date"
#printing the full date sent from the server to the command line
case $weekday in
#comparing the current weekday to the string on the next line
	Friday)
#comparing the to current weekday
echo "Yay, it's finally Friday!";;
#printing this line to the screen when the info sent from the server mathes "friday"
	Saturday)
#comparing the string saturday to the current weekday sent from the server
echo "There are 6 days until Friday.";;
#printing this line to the screen when the current weekday doesn't match Friday
	Sunday)
#comparing the string sunday to the current weekday sent from the server
echo "There are 5 days until Friday.";;
#printing this line to the screen when the current weekday sent from the server doesnt match friday
	Monday)
#comparing the string monday to the current weekday sent from the server
echo "There are 4 days until Friday.";;
#printing this line to the screen when the current weekday sent from the server doesn't match friday
	Tuesday)
#comparing the string tuesday to  the current weekday sent from the server
echo "There are 3 days until Friday.";;
#printing this line to the screen when the current weekday sent from the server doesn't match friday
	Wednesday)
#comparing the string wendesday to the current weekday sent from the server
echo "There are 2 days until Friday.";;
#printing this line to the screen when the current weekday sent from the server doesnt match friday
	Thursday)
#comparing the string thursday to the current weekday sent from the server
echo "There is 1 day until Friday.";;
#printing this line to the screen when the current weekday sent from the server doesnt match friday
esac
#ends case statement


geeky_holiday=$(awk "/$todays_date/" GeekyHolidays.txt)
assigns a variable to the awk used and server generated information to search through the geekyholidays txt file
geek_compare=$(cat /home/adiveglia6163/bin/GeekyHolidays.txt | grep "$geeky_holiday")
#assings a variable that  compares the geekyholidays txt file to the actual day to see if the day is a holiday
	if [ "$geek_compare" > "0" ]
#starts an if statement to compare the geekytxt to the current date in search for a match higher than 0
	then
#points to the internal code that will execute when the if statement is true
	echo "Today is the $geeky_holiday"
#prints the current geeky holiday line to the screen if the if statement is determined true	
	else
# assigns other output to execute when the if statement is false
	echo "Today is not a Geeky Holiday."
#prints this line to the command line when the current day isn't a geeky holiday
	fi
#ends if statement
