import sys

if len(sys.argv) != 2:
    print("bad input")
    #sys.exit(1)
    file = "2024/d6/p1/example.2"
else:
    file = sys.argv[1]

with open(file, "r") as fd:
    file = fd.readlines()

new_file = []
player = []
X = 1
Y = 0
POSTIONS = "v<^>"
IDX_POSITIONS = 0

for y, line in enumerate(file):
    new_file.append(list(line.strip()))
    for x, c in enumerate(line):

        if c in POSTIONS:
            IDX_POSITIONS = POSTIONS.index(c)
            player = {
                "pos": [y, x],
                "dir": [1, 1]
            }
            match POSTIONS[IDX_POSITIONS]:
                case "v":
                    player["dir"][X] = 0
                    player["dir"][Y] = 1
                case "<":
                    player["dir"][X] = -1
                    player["dir"][Y] = 0
                case "^":
                    player["dir"][X] = 0
                    player["dir"][Y] = -1
                case ">":
                    player["dir"][X] = 1
                    player["dir"][Y] = 0

X_BOUNDARY = len(file[0])
Y_BOUNDARY = len(file)
file = new_file

def print_board():

    print()
    for line in file:
        for c in line:
            print(c, end="")
        print()
    print()

while True:

    player_X_coord = player["pos"][X]
    player_Y_coord = player["pos"][Y]
    file[player_Y_coord][player_X_coord] = "X"
    # print_board()

    X_coord = player_X_coord + player["dir"][X]
    Y_coord = player_Y_coord + player["dir"][Y]

    if X_coord >= X_BOUNDARY or X_coord < 0:
        break

    if Y_coord >= Y_BOUNDARY or Y_coord < 0:
        break

    if file[Y_coord][X_coord] == "#":
        IDX_POSITIONS = (IDX_POSITIONS + 1) % 4
        match POSTIONS[IDX_POSITIONS]:
            case "v":
                player["dir"][X] = 0
                player["dir"][Y] = 1
            case "<":
                player["dir"][X] = -1
                player["dir"][Y] = 0
            case "^":
                player["dir"][X] = 0
                player["dir"][Y] = -1
            case ">":
                player["dir"][X] = 1
                player["dir"][Y] = 0

    player["pos"][X] += player["dir"][X]
    player["pos"][Y] += player["dir"][Y]

total = 0
positions = 0
for line in file:
    total += line.count("X")
    positions += len(line)

print(f"total: {total}")
print(f"positions: {positions}")