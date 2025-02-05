import sys

if len(sys.argv) != 2:
    print("bad input")
    #sys.exit(1)
    file = "2024/d6/p1/example.2"
else:
    file = sys.argv[1]

with open(file, "r") as fd:
    file = fd.readlines()
