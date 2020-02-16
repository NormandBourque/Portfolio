#!/bin/sh
#shebang line orienting the document as a bash script
sleep 100 &
#creates a junk file to run in the background called "sleep 100"
sleep 1000 &
#creates a junk file to run in the background called "sleep 1000"
sleep 2000 &
#creates a junk file to run in the background called "sleep 2000"
ps
#lists the current jobs owned by the user
echo "Which process would you like to terminate?"
#asks the user for input on which program they would like to terminate
read input
#assigns input as a variable
kill $input
#applies the users input to the kill command to terminate the job
ps
#tests the script's functioning by relisting the curent user's jobs to display the kill
