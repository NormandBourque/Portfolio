#!/bin/sh
echo "What directory would you like to copy into a tarball?"
read directory
echo "What would you like to name your backup tarball?"
read tar_backup
todays_date=$(date +"%m_%d_%Y")
this_file=$(ls | grep -c "$tar_backup")
	if [ "$this_file" -gt "0" ]
		then
			echo "$tar_backup already exists."
	else 
			 tar -czvf $tar_backup$todays_date.tar.gz $directory
	fi
