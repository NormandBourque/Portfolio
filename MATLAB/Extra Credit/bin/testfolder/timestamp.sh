#!/bin/sh
#shebang line
current_time=$(date +"%T")
#formats appropriate time stamp from server and saves it to a variable
#http://www.cyberciti.biz/faq/howto-set-date-time-from-linux-command-prompt/
files_only=$(find . -maxdepth 1 -type f)
#assigns a command sequence that only lists files to a variable
#http://stackoverflow.com/questions/10574794/bash-how-to-list-only-files
for file in $files_only
#initiates for loop comparing the directories files to the variable that only lists files
        do
#initiates the command for the internal commands to execute as long as the former statement matches
                mv "$file" "$file$current_time"
#initiates a changing of the file to the same name with a timestamp from the server at the end
        done
#completes the loop
mv timestamp.sh* timestamp.sh
#changes the timestamp.sh file back from being changed in the loop with the test files
