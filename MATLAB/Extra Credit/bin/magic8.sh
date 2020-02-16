#!/bin/sh
#shebang line
echo "Would you like to ask the magic 8 ball? yes/no"
#asks user for input
read userinput
#stores user input

if [ "$userinput" = "yes" ];
#creates an if statement
	then 
#points comparison of if statement

		aRandomNumber=$((RANDOM % 10))
#assings a variable to random number generato
		echo "$aRandomNumber"
#prints random number generated

	case "$aRandomNumber" in
#creates a case statement 
	0)
#creates case 1
		echo "I'd sleep on it.";;
#prints this line if generated number matches case
	1)
#creates case 2
		echo "Ask and you shall receive.";;
#prints this line if generated number matches case
	2)
#creates case 3
		echo "Yahtzee!";;
#prints this line if generated number matches case
	3)
#creates case 4
		echo "Bingo!";;
#prints this line if generated number matches case
	4)
#creates case 5
		echo "Run free, young grasshopper.";;
#prints this line if generated number matches
	5)
#creates case 6
		echo "If you build it, it will come.";;
#prints this line if generated number matches
	6)
#creates case 7
		echo "If you're not first, you're last!";;
#prints this line if generated number mathces
	7)
#Creates case 8
		echo "It's not drinking alone if your dogs are home.";;
#prints this line if generated number matches
	8)
#creates case 9
		echo "Get a life.";;
#prints this line if generated number matches
	9)
#creates case 10
		echo "When pigs fly.";;
#prints this line if generated number matches
	esac
#ends case statement
else
#gives alternative 
	echo "uh.ok."
#prints this line if user input is not recognized
fi
#ends if else
