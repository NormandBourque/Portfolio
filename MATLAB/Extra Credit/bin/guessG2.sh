#!/bin/sh
high_pick=21
user_pick=1
aRandom=$((RANDOM % 20))

until [ $user_pick = $aRandom ] || [ $user_pick = "y" ]
        do
        echo "Pick a number between 0 and 20 or hit the 'y' key to quit...."
        read user_pick
	user_pick=`expr $user_pick + 1`
if [ $user_pick = $aRandom ] #f user pick == random number isn't the game done?????
       then
        echo "You are good! The magic number was: $aRandom!"
        elif [ $user_pick != $aRandom ] 
                then
                if ![ "$user_pick" =~ "^[0-20]+$" ] #&& [ $user_pick -lt $aRandom ] #thiis doesn't work
                        then
                        echo "Too low.."
                elif [ $user_pick != "y" ] #&& [ $user_pick -ge $high_pick ] 
                        then
                        echo "The options range from 0-20 doofus..."
                elif [ $user_pick -gt $aRandom ] #this works
                        then
			echo "Too high..."
                else
                        if [ $user_pick = "y" ] #this works
                                then
                                echo "game over."
                        fi

                fi

fi
done

