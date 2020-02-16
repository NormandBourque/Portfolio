#/bin/sh
#shebang line

echo "Pick a number to start with..."
#asks user for input for number to countdown from
read number
#saves the users unput to a variable named "number"

until [ $number -eq 0 ]
#starts a "do until" loop comparing the user chosen number to 0
	do
#starts the loop by telling the loop to do the internal code
	echo "$number"
#prints the number to the screen
	number=`expr $number - 1`
#minuses 1 from the number before which enables the loop to countdown
done
#finishes the loop
