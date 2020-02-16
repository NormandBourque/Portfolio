#!/bin/sh
#shebang line
echo "Would you like to go on an adventure?! yes/no?"
#prints line asking user for input
read userinput
#stores the user input
if [ "$userinput" = "yes" ];
#creates an if statement to compare user input to a string
	then
#gives a statement if the user input matches the string
	echo "So, your imaginary mom asks you to take an imaginary walk down your imaginary street and get her imaginary eggs for her imaginary homemade cookies at the imaginary convenient store local to your imaginary house. Next,  you are opening the imaginary door in your bedroom and walking into your hallway. When you reach your hallway, you are putting on your shoes and then your coach. Now you are opening the imaginary door to your imarinary apartment and heading down the stairs. Now you open your imaginary front door and have the option take a right or a left down your imaginary street. Which way do you choose? right/left?"
#prints paragraph to the screen if user input matches the compared string
		read frontdoor
#stores more user input
		if [ "$frontdoor" = "right" ];
#creates a nested if statement to compare user input to a string
			then
#gives a statement if the user input matches the string
		echo "You take three steps down the imaginary street after you choose to turn right down the imaginary road. That's when you step in a big steaming pile of dog shit. Now you can either turn back and go home to your imaginary mommy and have her clean your shoes, or you can wipe it off on a few leaves and rocks and continue on your adventure? home/wipe?"
#prints paragraph to the screen if user input matches the compared string.
			read dogpoo 
#stores the user input
			if [ "$dogpoo" = "wipe" ];
#creates an if statement to compare user input to a string.
				then
#gives a statement if the user input matches the string.
			echo "Great, now you can continue on your way to the imaginary convenience store and get your imaginary mother her imaginary eggs for her imaginary homemade chocolate chip cookies. You come to a fork in the road, you think that it would be a shorter walk to take a right-- but you remember that left is pretty quick too. Which way do you turn? L/R?"
#prints paragraph to the screen if user input matches the compared string.
				read turn
#stores the user input
					if [ "$turn" = "L" ];
#creates a nested if statement to compare user input to a string.
						then
#gives a statement if the user input matches the string.
					echo "You make it down to the imaginary store in 7 minutes."
#prints line to the screen if user input matches the compared string.
					elif [ "$turn" = "R" ];
#gives an alternative comparison for the user to input something different
						then
#gives a different statement if the user input matches a different string.
					echo "You make it to the imaginary store in 6 minutes. One minute quicker!"
#prints line to the screen if user input matches the alternative compared string.
					fi
#ends the if/else statement
			elif [ "$dogpoo" = "home" ];
#gives an alternative comparison to the nested if statement for the dog poop situation
				then
#gives a different statement if the user input matches the alternative user input to a different string.
			echo "Clearly you can dish it out, but you cannot take it. A little poo never hurt anyone! How are you going to make it up to your mom? Either you have to do the dishes after dinner or scoop the kitty litter box. Is it going to be dishes/litter?"
#prints paragraph to the screen if user input matches the alternative compared string for the dog poop scenario
				read makeup
#stores more user input for another nested if staement
					if [ "$makeup" = "dishes" ];
#creates a nested if statement to compare user input to a string
						then
#gives a statement if the user input matches the string
						echo "Get to scrubbing, Mom made meatloaf!"
#prints line to the screen if user input matches the compared string
					elif [ "$makeup" = "litter" ];
#prints alternative line to the screen if user input matches the alternative string
						then
#gives a statement if the user input matches the alternative string
						echo "Get your scoop on, Kitty poops like a teenage boy with the constant munchies! YUCK!"  
#prints ne to the screen if the user input matches the alternative string
			fi
#ends nested if/else statement		
fi
#ends main if else statement 
		elif [ "$frontdoor" = "left" ];
#gives alternative comparison for user input from original if/else statement
			then
#gives a statement if the user input matches the alternative string fromt he original if statment
		echo " You walk a few yards and suddenly the fire hydrant in the middle of your street bursts causing a major flood. I hope that you can swim! Can you? y/n?"
#prints line to the screen if the user input mathces the alternative comparison for the original if statement/
			read swim
#sotres more user input another nested if/else statement
				if [ "$swim" = "y" ];
#creates a nester if statement to compare user input to a string
					then
#gives a statement if the user input matches the string
					echo "Goggle up and butterfly!"
#prints line to the screen if the user input matches the string
				elif [ "$swim" = "n" ];
#gives alternative comparison for user input.
					then
#gives a statement if the yser input matches the alternative string from the original statement
					echo "I'll never let go, Jack....."
#prints line if the alternative comparison matches the alternative string.
				fi
#ends the nested if else statement
		fi
#ends the parent if/else statement to the former nested if/else
elif [ "$userinput" = "no" ];
#gives an alternative comparison to the main if/else statement
	then
#gives a statement if the user input matches the alternative string from the main if else statement
	echo "Clearly you are not very adventurous."
#prints this line when the user input matches the alternative string.


fi
#ends the main if else statement

