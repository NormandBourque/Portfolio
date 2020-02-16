#!/bin/sh
#shebang line
echo "What directory would you like to copy into a tarball?"
#echo asking the user for input for the directory that they desire to tar
read directory
#saves the user input to a variable
echo "What would you like to name your backup tarball?"
#asks the user to name their tarball
read tar_backup
#saves the user input to a variable
todays_date=$(date +"%m_%d_%Y")
#creates a variable of their desired time stamp that will be sent from the server and appended to the tarball
this_file=$(ls | grep -c "$tar_backup")
#creates a variable to compare the desired tarball name to the rest of the files in my current directory
	if [ "$this_file" -gt "0" ]
#starts an if statement to compare the file search variable to an integer to ensure that the name isnt already taken
		then
#directs to the internal code of the if statement
			echo "$tar_backup already exists."
#prints the line that the name already exists if the if statement comes back true
	else 
#points to the code that executes if the if statement is false
		tar -czvf $tar_backup$todays_date.tar.gz $directory
#creates a zipped tarball of the specified directory with a user chosen quaranteed uniqe name with the approproate date.
	fi
#ends the if statement
