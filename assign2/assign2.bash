#!/bin/bash
input_file="$1"
output_file="${input_file}_formatted.c"

sed -E '/\/\//! s/([^_])_+([^_])/\1_\2/g' $input_file > temp.txt
sed -E ' s/_+$//g' temp.txt > temp2.txt

rm temp.txt temp2.txt
