#!/bin/sh
#shebang line

m=10
#assings a variable to 10, for 10 monkies
	until [ $m -eq 0 ]
#initiates a counting loop that compares the original 10 to 0
		do
#initiates the following inner parameters to execute
			echo "$m little monkies jumping on a bed, one jumped up and bumped his head. Mom called the doctor and the doctor said, 'no more monkies jumping on a bed!'"
#prints the former phrase to the screen
			m=`expr $m - 1`
#increments down from original number
		done
#ends loop
