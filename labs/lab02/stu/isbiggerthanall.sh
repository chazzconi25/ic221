#!/bin/bash
if [ $# -lt 2 ]
then
  echo "ERROR: Require a size and at least one file" 1>&2
  exit 1
elif ! [ $1 -eq $1 ]  # check if it's a number 
then
  echo "ERROR: Require a number for size" 1>&2
  exit 2
elif [ $1 -lt 0 ] 
then
  echo "ERROR: Require a positive number for size" 1>&2
  exit 3
elif [ ! -e $2 ]
then
  echo "ERROR: File $2 does not exist" 1>&2
else
  for file in $*
  do
    if [ -e $file ]
    then
      if [ $(wc -c $file | cut -d " " -f 1) -ge $1 ]
      then
        echo $file
      fi
    fi
  done
fi
