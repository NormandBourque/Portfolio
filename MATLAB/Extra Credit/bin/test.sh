#!/bin/sh
#shebang line
echo "Would you like to go on an adventure?! yes/no?"
read userinput
if [ "$userinput" = "yes" ];
	then
	echo "So, you are opening the imaginary door in your bedroom and walking into your hallway. When you reach your hallway, you are putting on your shoes and then your coach. Now you are opening the imaginary door to your imarinary apartment and heading down the stairs. Now you open your imaginary front door and have the option take a right or a left down your imaginary street. Which way do you choose? right/left?"
elif [ "$userinput" = "no" ];
	then
	echo "user said no"
fi
#Ok you are on the right track but the way to make it less complicated is to do one if statement at a time.  Ie if yes then do the if no 
#does that make sense?
# i think so, that;s what i think that i was trying to do, but i was afraid that it would get really messy. if i then do the same thing with the "no" that i did with the "yes" would that make sense?
#yes that way you can keep it organized.  if you want to make sure it works you could finish that if and then try it.
