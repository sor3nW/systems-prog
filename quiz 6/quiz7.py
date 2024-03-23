import sys

f = open(sys.argv[1], "r")
even = 0
for line in f:
    if even % 2 == 0:
        print(line)
    even += 1

