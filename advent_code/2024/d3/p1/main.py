import sys

if len(sys.argv) != 2:
    print("bad input")
    sys.exit(1)

with open(sys.argv[1], "r") as fd:
    file = fd.readlines()

total = 0
for line in file:
    
    operations = line.split("mul(")
    for operation in operations:

        if not ")" in operation or not "," in operation:
            continue

        parts = operation.split(")")[0]
        if parts.count(",") != 1:
            continue

        parts = parts.split(",")
        try:
            if parts[0].isdigit() and parts[1].isdigit():
                mul = (int(parts[0]) * int(parts[1]))
                print(parts)
                total += mul
        except:
            pass
print(total)