#!/bin/bash

STR=""
./check $STR > /dev/null 2>&1
VAL=$?
while [ $VAL -ne 0 ]
do
    for var in {1..16}
    do
        STR="$STR$(($RANDOM % 9))"
    done
    RETURN=$STR
    ./check $STR > /dev/null 2>&1
    VAL=$?
    STR=""
done
echo $RETURN