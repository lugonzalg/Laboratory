import sys
from collections import Counter

if len(sys.argv) != 2:
    print("bad input")
    sys.exit(1)

with open(sys.argv[1], "r") as fd:
    file = fd.readlines()

arr_n = []
arr_m = []

for line in file:
    values = line.split()
    if len(values) != 2:
        print(f"error with line: {line}")

    arr_n.append(int(values[0].strip()))
    arr_m.append(int(values[1].strip()))

counter_m = Counter(arr_m)

total = 0
for n in arr_n:
    total += n * counter_m[n]

print(total)
