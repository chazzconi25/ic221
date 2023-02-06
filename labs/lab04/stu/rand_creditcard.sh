#!/bin/bash

STR=""
for var in {1..16}
do
    STR="$STR$(($RANDOM % 9))"
done
./check $STR | cat -