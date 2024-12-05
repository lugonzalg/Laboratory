import sys

if len(sys.argv) != 2:
    print("bad input")
    #sys.exit(1)
    file = "advent_code/2024/d5/p1/example.1"
else:
    file = sys.argv[1]

with open(file, "r") as fd:
    file = fd.readlines()

file = [line.strip() for line in file]

kv = {}

idx = 0
while idx < len(file):

    line = file[idx]
    if not line:
        break

    line = line.split("|")

    if line[0] not in kv:
        kv[line[0]] = [line[1]]
    else:
        kv[line[0]].append(line[1])
    idx += 1

sanis = []
def fix(idx: int, line: str):
    nums = list(map(str, line[idx].split(",")))

    sani = [nums.pop(0)]
    for num in nums:
        last_correct_pos = len(sani)
        for idx, s in enumerate(sani):
            if s not in kv or num not in kv[s]:
                last_correct_pos = idx
                break
        sani.insert(last_correct_pos, num)
    sanis.append(sani)

good_idx = []
idx += 1
while idx < len(file):
    wrote = set()
    breaky = False
    for elem in file[idx].split(","):
        if elem in kv:
            for w in wrote:
                if w in kv[elem]:
                    breaky = True
        if breaky:
            fix(idx, file)
            good_idx.append(idx)
            break
        wrote.add(elem)
    idx += 1

total = 0
for idx in good_idx:
    nums = list(map(int, file[idx].split(",")))
    n = len(nums)
    mid = int(n/2)
    total += int(nums[mid])

total2 = 0
for sani in sanis:
    n = len(sani)
    mid = int(n/2)
    total2 += int(sani[mid])

print(good_idx)
print(total)
print(total2)