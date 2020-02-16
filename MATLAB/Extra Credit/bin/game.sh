#!/bin/sh
high_pick="21"
user_pick=1
aRandomNumber=$((RANDOM % 20))
until [[ "$user_pick" -eq $aRandomNumber ]] #|| "$user_pick" -eq "m" ]]
	do
        echo "pick a number between 1 and 20... For mercy, key 'm'!"
        read user_pick

                if [ "$user_pick" -lt  "$aRandomNumber" ]
                        then
                        echo "Too low.. like your life. Mercy? Key 'm'"
				if [ "$user_pick" = "m" ]
                elif [[ "$user_pick" > $aRandomNumber ]] #&& $user_pick -lt $high_pick ]]
                        then
                        echo "Too high. Like your mom was when she dropped you as a baby. Mercy? Key 'm'"
					if [ "$user_pick" -eq "m" ]
		 elif [[ "$user_pick" -ge "$high_pick" ]]
                        then
                        echo "Uh, that is not between 1 and 20 doofus.... Ready for mercy already? Key 'm'"
                				if [ "$user_pick" -eq "m" ]
		else
                        echo "Oh you filthy scoundrel, you are good!"
                        echo "The magic number was: $aRandomNumber!"
 					then 
				echo "game over, loser."	
                		fi
						then
					echo "game over, loser."
					fi
							then
						echo "game over, loser."
						fi
					


		fi		
	done

#if [ "$user_pick" -ne "$aRandomNumber" ]
#then
# echo "Mercy? Key 'm'"
#read uncle
#else 
#echo "good game."
#fi

#if [ $uncle -eq "m"]
#echo "quitter"

