#!/bin/sh
#shebang line
echo "When do you want your multiplication table to end?"
#asks the user what number they want the multiplication table to go up to
read end
#saves the user input to a variable
y=1
#assigns a value for the Y axis to begin at
while [ $y -le "$end" ]
#starts a while loop suggesting that the internal code continues while the incremented Y axis points are less than or equal to the user input
	do
#executes the internal code
		x=1
#assigns a value for the X axis to begin at-- X and Y are assigned the same value to keep the table consistent
		while [ $x -le "$end" ]
#starts a while loop suggesting that the internal code continues to execute while the incremented X axis points remain less than or equal to the user input
		do
#executes the internal code
		sum=`expr $x \* $y`
#assigns a variable to the multiplication operation between X and Y
			printf "% 3i" "$sum"
#uses printf instead of echo since offers the 3i spacing feature to give room between the printed sums
			x=`expr $x + 1`
#increments the X axis points by plus 1
			
		done
#ends the nested while loop
	echo ""
#echoes a blank line to properly format the Y coordinate points so that they are not all next to each other
	y=`expr $y + 1`
#increments the Y axis points by plus 1
	done
#ends the main while loop
