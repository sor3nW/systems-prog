#!/bin/bash

sed -E -e '
# Remove lines starting with "%"
/^%/d

# Fix comments starting with "//" or "#"
s/^([[:space:]]*)(\/\/|#)[[:space:]]*/\/\/ /g
' file1.php > file1Clean.php

