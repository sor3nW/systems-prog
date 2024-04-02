#!/bin/bash

if [ "$#" -lt 1 ]; then
    echo "needs atleast Two arguments"
    echo "Usage: assign3.bash <filename>"
    exit 1
fi
awk -f assign3.awk "$@" > awkInputFiltered.csv