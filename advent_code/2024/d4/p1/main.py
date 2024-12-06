import sys

if len(sys.argv) != 2:
    print("bad input")
    #sys.exit(1)
    file = "advent_code/2024/d4/p1/example.1"
else:
    file = sys.argv[1]

with open(file, "r") as fd:
    file = fd.readlines()

file = [line.strip() for line in file]

n = len(file)
m = len(file[0])
XMAS = "XMAS"
SAMX = "SAMX"

total = 0
total2 = 0
# swap y<->x
for r in range(m):
    for c in range(n): 
        if c+3<n and file[r][c] == "X" and file[r][c + 1] == "M" and file[r][c + 2] == "A" and file[r][c + 3] == "S":
            total += 1
        if c+3<n and file[r][c] == "S" and file[r][c + 1] == "A" and file[r][c + 2] == "M" and file[r][c + 3] == "X":
            total += 1

        if r+3<m and file[r][c] == "X" and file[r + 1][c] == "M" and file[r + 2][c] == "A" and file[r + 3][c] == "S":
            total += 1
        if r+3<m and file[r][c] == "S" and file[r + 1][c] == "A" and file[r + 2][c] == "M" and file[r + 3][c] == "X":
            total += 1

        if c+3<n and r+3<m and file[r][c] == "X" and file[r + 1][c + 1] == "M" and file[r + 2][c + 2] == "A" and file[r + 3][c + 3] == "S":
            total += 1
        if c+3<n and r+3<m and file[r][c] == "S" and file[r + 1][c + 1] == "A" and file[r + 2][c + 2] == "M" and file[r + 3][c + 3] == "X":
            total += 1

        if n - 3 - c > 0 and r+3<m and file[r][n - 1- c] == "X" and file[r + 1][n - 2 - c] == "M" and file[r + 2][n - 3 - c] == "A" and file[r + 3][n - 4 - c] == "S":
            total += 1
        if n - 3 - c > 0 and r+3<m and file[r][n - 1- c] == "S" and file[r + 1][n - 2 - c] == "A" and file[r + 2][n - 3 -c] == "M" and file[r + 3][n - 4 - c] == "X":
            total += 1

        if r+2<m and c+2<n and file[r][c] == "M" and file[r+1][c+1] == "A" and file[r+2][c+2] == "S" and file[r][c + 2] == "M" and file[r+2][c] == "S":
            total2 += 1

        if r+2<m and c+2<n and file[r][c] == "S" and file[r+1][c+1] == "A" and file[r+2][c+2] == "M" and file[r][c + 2] == "S" and file[r+2][c] == "M":
            total2 += 1

        if r+2<m and c+2<n and file[r][c] == "S" and file[r+1][c+1] == "A" and file[r+2][c+2] == "M" and file[r][c + 2] == "M" and file[r+2][c] == "S":
            total2 += 1

        if r+2<m and c+2<n and file[r][c] == "M" and file[r+1][c+1] == "A" and file[r+2][c+2] == "S" and file[r][c + 2] == "S" and file[r+2][c] == "M":
            total2 += 1


print(f"total: {total}")
print(f"total: {total2}")