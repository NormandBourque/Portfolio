#!/bin/sh
high_pick="21"
user_pick=1
aRandomNumber=$((RANDOM % 20))
until [[ "$user_pick" -eq $aRandomNumber ]] #|| "$user_pick" -eq "m" ]];
        do
        echo "pick a number between 1 and 20 or key any letter for mercy!"
        read user_pick
                if [ "$user_pick" -lt  $aRandomNumber ]
                        then
                        echo "Too low.. like your life."
                elif [[ "$user_pick" -gt "$aRandomNumber" && "$user_pick" -lt "$high_pick" ]]
                        then
                        echo "Too high. Like your mom was when she dropped you as a baby."
                elif [[ "$user_pick" -ge "$high_pick" ]]
                        then
                        echo "Uh, that is not between 0 and 20 doofus...."
                else
                        echo "Oh you filthy scoundrel, you are good!"
                        echo "The magic number was: $aRandomNumber!"

                fi
sum="m += 1"
                if [[ $user_pick -eq  "$sum" ]]
                        then
                        echo "HAHA, L 7 WEENIE!"
               # elif [ "$user_pick" == "M" ]
                #       then
                #       echo "Wrong 'm' for Mercy-- but BYE anyway."
		fi
        done

