#!/bin/sh

echo "this is going to print the user and the shell they are using from /etc/passwd"

#awk searches /etc/passwd
#-F specifies the delimiter for each field as :
# the variables used are the ones that are the user and the shell
awk -F: '{print $1 ":" $7}' /etc/passwd
