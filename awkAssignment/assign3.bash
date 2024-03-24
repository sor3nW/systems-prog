#!/bin/bash

if [ "$#" -lt 1 ]; then
    echo "needs atleast Two arguments"
    echo "Usage: assign3.bash <filename>"
    exit 1
fi

for file in "$@"; do
    if [ -f "$file" ]; then
        awk -f assign3.awk "$file" > "$file"Filtered.csv
    else
        echo "$file"
    fi
done