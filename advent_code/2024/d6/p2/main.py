import sys

if len(sys.argv) != 2:
    print("bad input")
    #sys.exit(1)
    file = "2024/d6/p2/example.1"
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
            START_IDX_POSIOTIONS = IDX_POSITIONS
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

            player_starting = {
                "pos": [y, x],
                "dir": [0, 0]
            }
            player_starting["dir"][X] = player["dir"][X]
            player_starting["dir"][Y] = player["dir"][Y]

X_BOUNDARY = len(file[0])
Y_BOUNDARY = len(file)
file = new_file
total2 = 0

def print_board():

    print()
    for line in file:
        for c in line:
            print(c, end="")
        print()
    print()

from copy import deepcopy

for y in range(len(file)):
    print("new_y")
    for x in range(len(file[0])):
        colission_pos = []
        if file[y][x] != ".":
            continue
        print(f"x: {x}")
        print(f"y: {y}")
        print(f"total2: {total2}")

        file[y][x] = "#"
        print_board()
        coord_memory = {}
        player = deepcopy(player_starting)
        IDX_POSITIONS = START_IDX_POSIOTIONS
        while True:

            player_X_coord = player["pos"][X]
            player_Y_coord = player["pos"][Y]
            file[player_Y_coord][player_X_coord] = "x"
            print_board()
            file[player_Y_coord][player_X_coord] = "."
            # file[player_Y_coord][player_X_coord] = "X"

            X_coord = player_X_coord + player["dir"][X]
            Y_coord = player_Y_coord + player["dir"][Y]

            player_coords = str(player_Y_coord, player_Y_coord)
            if player_coords not in coord_memory:
                coord_memory[player_coords] = 1
            else:
            if X_coord >= X_BOUNDARY - 1 or X_coord < 0:
                break

            if Y_coord >= Y_BOUNDARY or Y_coord < 0:
                break

            if file[Y_coord][X_coord] == "#":

                colission_pos.append([player_Y_coord,player_X_coord])
                if len(colission_pos) >= 8:
                    if colission_pos[-8:-4] == colission_pos[-4:]:
                        total2 += 1
                        break
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

        file[y][x] = "."

total = 0
positions = 0
for line in file:
    total += line.count("X")
    positions += len(line)

print(f"total: {total}")
print(f"total2: {total2}")
print(f"positions: {positions}")