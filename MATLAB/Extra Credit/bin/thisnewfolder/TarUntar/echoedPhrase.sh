#!/bin/sh
#Shebang line
echo "Choose a numnber between 1 and 10?"
#Asks user for numeric input
read number
#Stores numeric input to a variable
echo "Tell me a phrase..."
#Asks user to type a phrase or a sentence
read phrase
#Stores phrase to a variable
n=0
#Assigns 0 as the starting point for the counting loop
	while [ $n -lt $number ]
#Suggests the start of a while counting loop giving a base starting point and comparing it to the user numeric input
	do
#Suggests the execution of following statements while the former statement isnt met
		echo "$phrase"
#Prints the phrase that was chosen by the user
		n=`expr $n + 1`
#Adds the number of printed phrases to compare to the users numeric input
	done
#Ends the loop

