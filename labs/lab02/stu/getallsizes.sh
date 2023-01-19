#!/bin/bash

i=1
for arg in $*
do  
  if [ -e $arg ] 
  then
    echo $arg $(wc -c $arg | cut -d " " -f 1)
    let i++
  else
    echo "ERROR: File $arg does not exist" 1>&2
  fi
done
