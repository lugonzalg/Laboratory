import sys

if len(sys.argv) != 2:
    print("bad input")
    sys.exit(1)

with open(sys.argv[1], "r") as fd:
    file = fd.readlines()

def check_seq(numbers: list[int]):
    if numbers[0] == numbers[1]:
        numbers.pop(0)
        return True

    idx = 1
    is_incremental = numbers[0] < numbers[1]
    is_decremental = numbers[0] > numbers[1]
    prev_n = numbers[0]

    while idx < 3:

        result = prev_n - numbers[idx]
        if (is_decremental and (result > 3 or result <= 0)) \
            or (is_incremental and (result < -3 or result >= 0)) \
            or (abs(result) > 3 or result == 0):

                numbers.pop()
                break


total = 0
for line in file:
    numbers = line.split()

    numbers = list(map(int, numbers))

    number_seq = [numbers[0],numbers[1]]
    extra = True
    for n in numbers[2:]:

        number_seq.append(n)
        if not check_seq(number_seq):
            if not extra:
                break
            extra = False
    else:
        total += 1

print(f"result: {total}")