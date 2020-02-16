#!/bin/sh
#shebang line
todays_date=$(date +"%A")
#assings a variable to todays date and assigns the variable to call for just the weekday's name.
echo "Today is $todays_date."
#prints the servers understanding of the current weekday.
case $todays_date in
#sets up a case statement to compare the output from the server to statements suggested strings below.
	 Friday)
#asks to compare the string sent from the server to "Friday"
echo "Friday is here! Get crunk!";;
#prints this line if the statement matches the string sent from the server.
	Saturday)
#asks to compare the strng sent from the server to "Saturday"
echo "6 days until Friday. :(";;
#prints this line if the statement matches the string sent from the server.
	Sunday)
#asks to compare the string sent from the server to "Sunday."
echo "5 days until Friday. :(";;
#prints this line if the statement matches the string sent from the server.
	Monday)
#asks to compare the string sent from the server to "Monday."
echo "4 days until Friday. :(";;
#prints this line if the statement matches the string sent from the server.
	Tuesday)
#asks to compare the string sent from the server to "Tuesday."
echo "3 days until Friday...:-/";;
#prints this line if the statement matches the string sent from the server.
	Wednesday)
#asks to compare the string sent from the server to "Wednesday."
echo "2 days until Friday... :-]";;
#prints this line if the statement matches the string sent from the server.
	Thursday)
#asks to compare the string sent from the server to "Thursday."
echo "1 day until Friday... :-)";; 
#prints this line if the statement matches the string sent from the server.
esac
#ends the case statement.
