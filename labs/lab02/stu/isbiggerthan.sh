#!/bin/bash
echo $1
if [ $# -eq 0 ] 2> /dev/null
then
  echo "ERROR: Require path and size"
elif [ ! $("$1" -eq "$1") ] 2> /dev/null  # check if it's a number 
then
    echo "ERROR: Require a number for size"
elif [ $1 -lt 0 ] 2> /dev/null 
then
  echo "ERROR: Require a positive number for size"
elif [ -e $2 ]
then
  echo "ERROR: File $2 does not exist"
  echo $#
elif [ $(wc -c $2 | cut -d " " -f 1) -gt $1 ]
then
  echo yes
else
  echo no
fi
