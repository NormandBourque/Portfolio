#!/bin/sh
#shebang line to initiate bash script
echo "What would you like to name your new file?"
#asks the user for their keyed input
read filename
#creates a variable storing the users input
todays_date=$(date +"%m_%d_%Y")
#assigns a variable for the current date
#http://www.cyberciti.biz/faq/unix-linux-appleosx-bsd-shell-appending-date-to-filename/
touch $filename$todays_date
#creates a new file named by the user with the current date appended to it
echo "The file you just created is named: $filename$todays_date."
#tests that the new file and date rendered as the bash intended it to
