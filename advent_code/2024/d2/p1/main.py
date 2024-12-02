import sys

if len(sys.argv) != 2:
    print("bad input")
    sys.exit(1)

with open(sys.argv[1], "r") as fd:
    file = fd.readlines()

total = 0
for line in file:
    numbers = line.split()

    numbers = list(map(int, numbers))

    prev_n = numbers[0]
    is_incremental = is_decremental = False
    for n in numbers[1:]:

        if n < prev_n:
            is_decremental = True
        elif n > prev_n:
            is_incremental = True

        result = prev_n - n
        if is_decremental and (result > 3 or result <= 0):
            break
        elif is_incremental and (result < -3 or result >= 0):
            break
        elif abs(result) > 3 or result == 0:
            break

        prev_n = n
    else:
        print(numbers)
        if is_decremental != is_incremental:
            total += is_incremental | is_decremental

print(f"result: {total}")