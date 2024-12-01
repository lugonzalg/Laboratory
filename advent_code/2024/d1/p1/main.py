import sys

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

arr_n.sort()
arr_m.sort()

total = 0
for n, m in zip(arr_n, arr_m):
    total += abs(n - m)

print(total)

print(f"result: {sum(arr_m) - sum(arr_n)}")
