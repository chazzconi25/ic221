#!/bin/bash
if [ $# -eq 0 ]
then
  echo "ERROR: Require path and size" 1>&2
elif ! [ $1 -eq $1 ]  # check if it's a number 
then
  echo "ERROR: Require a number for size" 1>&2
elif [ $1 -lt 0 ] 
then
  echo "ERROR: Require a positive number for size" 1>&2
elif [ ! -e $2 ]
then
  echo "ERROR: File $2 does not exist" 1>&2
elif [ $(wc -c $2 | cut -d " " -f 1) -gt $1 ] || [ $(wc -c $2 | cut -d " " -f 1) -eq $1 ]
then
  echo yes
else
  echo no
fi
