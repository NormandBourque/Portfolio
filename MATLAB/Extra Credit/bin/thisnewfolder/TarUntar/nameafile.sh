#!/bin/sh
#shebang line
echo "Name your file...."
t
#asks user for input
read current_file
#stores user input
this_file=$(ls | grep -c "$current_file")
#assigns user input to a variable and using the count method to ensure that there is 0 files named the same thing
#http://alvinalexander.com/blog/post/linux-unix/linux-ls-command	
if [ "$this_file" -gt "0" ]
#creates an if statement
	then
#brings the statement to a print line
		echo "$current_file already exists."
#prits the line
	else
#gives an alternative to print
		 $(touch "$current_file")
#creates the file if it doesn't exist
	fi
#ends the if else statement
 
