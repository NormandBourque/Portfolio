#!/bin/sh
echo "Pick a number 0 through 20..."
read user_pick
aRandomNumber=$((RANDOM % 20))
until [ "$user_pick" -eq "$aRandomNumber" ]
	do
		if [ "$user_pick" -eq "$aRandomNumber" ]
			then
			echo "The magic number was: $aRandomNumber"
			echo "Oh, you filthy soundrel! You are good!"
		elif [ "$user_pick" -lt "$aRandomNumber" ]
			then
			echo "Too low. Just like your life."
			echo "Pick again..."
			read pick2
		elif [ "$user_pick" -gt "$aRandomNumber" ]
			then
			echo "Wicked high. Like you wish you were."
			echo "Pick again..."
			read pick3
		elif [ "$user_pick" -eq "" ]
			then
			echo "You too chicken to hit a few keys?! Come onnnnnn!"
			echo "Pick a number this time..."
			read pick4
		else 
			echo "Hit 'm' for for mercy if you are a total wuss and you know it.."
			read mercy
				if [ "$mercy" -eq "m" ]
				then
				x=1
				while [ "$x" -lt "100i" ]
					do
					echo "Loser!!!!!!!"
					x=`expr $x + 1`
				done
				else
					echo "I said hit 'm' dumb-dumb!"
				fi
		fi
done
					
