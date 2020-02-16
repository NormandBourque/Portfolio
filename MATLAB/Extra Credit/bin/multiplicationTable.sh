#!/bin/sh
#shebang line
echo "When do you want your multiplication table to end?"
#asks the user what number they want the multiplication table to go up to
read end
#saves the user input to a variable
a=1
#assigns a value for the vertical numbers to begin at
until [ $a -gt "$end" ]
#starts an until loop suggesting that the internal code continues to execute until the incremented vertical numbers are greater than the user input
        do
#executes the internal code
                b=1
#assigns a value for the horizontal numbers to begin at-- variables "a" and "b" are assigned the same value to keep the table consistent
                until [ $b -gt "$end" ]
#starts an until loop suggesting that the internal code continues to execute until the incremented horizontal number is greater than the user input
                do
#executes the internal code
                sum=`expr $b \* $a`
#assigns a variable to the multiplication operation between numbers on the horizonal and vertical line (variables "a" and "b")
                        printf "% 3i" "$sum"
#uses printf instead of echo since offers the 3i spacing feature to give room between the printed sums
                        b=`expr $b + 1`
#increments the horizontal numbers by plus 1

                done
#ends the nested until loop
        echo ""
#echoes a blank line to properly format the verticle numbers so that they are not all next to each other
        a=`expr $a + 1`
#increments the verticle numbers by plus 1
        done
#ends the main until loop
