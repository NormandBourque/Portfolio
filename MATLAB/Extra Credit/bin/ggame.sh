#!/bin/sh
high_pick=21
user_pick=0
aRandomNumber=$((RANDOM % 20))
inc_pick=($user_pick)
while [[ "$user_pick" -ne "$aRandomNumber" ]]
	do
	echo "Pick a number between 1 and 20 or key 'm' to quit."
	read user_pick
	if [[ "$user_pick" -eq "$aRandomNumber" ]]
	then
		echo "Good job!"
	fi
#	while [ "$inc_pick" = "m" ]
#		do
#		echo "game over."
#		done
	     mercy='y'
		for  mercy in y Y 
		do
			if [ "$mercy" = "$user_pick" ]
			then
			echo "game over."
			fi
		done
if [ -f $mercy  ]
	then
	echo "wimp."
	elif [[ "$user_pick" -lt "$aRandomNumber" && "$user_pick" != "$mercy" ]]
		then
		echo "Too low..."
	elif [[ "$user_pick" -gt "$aRandomNumber" ]]
		then
		echo "Too high..."
	elif [ "$user_pick" = "y" ]
		then
		echo "peace, weenie."
fi

	#else 
		#mercy='m'
		#
		#	for mercy in m M
		#	do
			#	if [ "$user_pick" = "m" ]
			#	then
			#	echo "game over."
			#	fi
			#done
	#else
	#	echo "Good job! The secret number was $aRandomNumber!"
	#fi
	done
