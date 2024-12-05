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

good_idx = []
idx += 1
while idx < len(file):
    wrote = []
    breaky = False
    for elem in file[idx].split(","):
        if elem in kv:
            for w in wrote:
                if w in kv[elem]:
                    breaky = True
        if breaky:
            break
        wrote.append(elem)
    else:
        good_idx.append(idx)
    idx += 1

total = 0
for idx in good_idx:
    nums = list(map(int, file[idx].split(",")))
    n = len(nums)
    mid = int(n/2)
    total += int(nums[mid])

print(good_idx)
print(total)