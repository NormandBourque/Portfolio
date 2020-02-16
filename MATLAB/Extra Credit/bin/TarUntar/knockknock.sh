#!/bin/sh
#shebang line
echo "knock, knock..."
#prints line asking user for input
read answer
#stores the user input
	if [ "$answer" = "Who's there?" ];
#creates an if/else statement
		then
#gives a statement if the user input matches the strng
			echo "Atch..."
#prints line to the screen when input matches string

read answer2
#stores more user input
		if [ "$answer2" = "Atch who?" ];
#creates a second if/else statement for different user input
			then
#gives a statement if the user input matches string
				echo "Bless you!"
#prints line to the screen when input matches string
		else 
#gives an alternative if input doesn't match string
			echo "Wrong answer."
#prints this line when input doesn't match
		fi
#ends second if/else
	else 
#gives another alternative if input doesnt match
		echo "Wrong answer."
#prints another line when input doesn't match

	fi 
#ends main if/else statement
