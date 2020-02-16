#!/bin/sh
#shebang line
echo "what would you like to name your file?"
read file_Name
vim='vi '
write=$vim$file_Name
$write
