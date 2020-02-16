#!/bin/sh
#shebang line
echo "How many verses would you like to hear?"
#asks the user how many verses they would like to hear
read verses
#saves the users chosen number of verses to a variable
n=100
#assigns a variable to the 100 that the program always has to begin at
i=`expr $n - $verses`
#assigns a variable to the number of bottles that the song needs to repeat to by subtracting the beginning number from the users chosen number
	until [ $n -eq $i ]
#initiates a counting loop that compares the original number to the number of bottles that the song must sing down to
	do
#executes the following internal code 
		echo "$n bottles of beer on the wall!"
#prints to the screen 
		n=`expr $n - 1`
#determines how many prints to the screen the former statement makes
	done
#ends the counting loop
