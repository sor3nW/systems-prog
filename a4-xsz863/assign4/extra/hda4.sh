#!/bin/bash

# Sam Silvestro
# CS 3424 - Systems Programming
# Spring 2024
# Assignment 4, helper utility
#
# Use: ./hda4.sh <courses_data_file>
# Function:
#		Displays the contents of a binary courses.dat file in a three-"column" display: offset,
#		29-byte hex view (grouped in terms of 8/8/8/5 bytes), and a 29-byte ASCII view.

[ $# -gt 0 ] || exit 1
tmpfile=$(mktemp --suffix=.txt .hda4fmt.XXX) || exit 1
echo '"%08_ax | " 8/1 "%02x " "  " 8/1 "%02x " "  " 8/1 "%02x " "  " 5/1 "%02x " " | "' > "$tmpfile"
echo '29/"%_p" "\n"' >> "$tmpfile"
hexdump -f "$tmpfile" "$@"
[ -e "$tmpfile" ] && rm "$tmpfile" 2>/dev/null
