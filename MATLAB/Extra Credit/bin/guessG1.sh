#!/bin/sh
high_pick=21
user_pick=1
aRandom=$((RANDOM % 20))

until [ $user_pick = $aRandom ] || [ $user_pick = "y" ];
	do
	echo "Pick a number between 0 and 20 or hit 'y' to quit...."
	read user_pick
if [ $user_pick = $aRandom ];
	then
	echo "You are good! The magic number was: $aRandom!"
	elif [ $user_pick != $aRandom ];
		then
		if [ $user_pick -lt $aRandom ]; #|| [ "$user_pick" != "y" ];
			then
			echo "Too low.."
		elif [ $user_pick -ge $high_pick ]; #&& [ "$user_pick" != "y" ];
			then
			echo "The options range from 0-20 doofus..."
		elif [ $userpick > $aRandom ] || [ $user_pick != "y" ];
			then 
			echo "Too high..."
		else
			if [ $user_pick = "y" ];
				then
				echo "When you cry for mercy, I laugh!"
			fi
				
		fi

fi
done

