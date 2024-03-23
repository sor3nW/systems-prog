#!/bin/bash

# Check if an input file is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <input_file>"
    exit 1
fi

input_file="$1"

# Print even lines
awk 'NR % 2 == 0' "$input_file"

# Count the total number of lines
total_lines=$(wc -l < "$input_file")

# Check if the total number of lines is greater than 10
if [ "$total_lines" -gt 10 ]; then
    echo "big"
else
    echo "small"
fi
