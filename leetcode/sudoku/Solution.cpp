#include <vector>
#include <cstring>
#include <stdint.h>
#include <ctype.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        uint8_t hash_map[2][10];

        for (size_t x = 0; x < 9; x++) {
            memset(hash_map, 0, sizeof(hash_map));
            for (size_t y = 0; y < 9; y++) {

                if (isdigit(board[y][x])) {
                    if (hash_map[0][board[y][x] - '0'])
                        return false;
                    hash_map[0][board[y][x] - '0']++;
                }
                if (isdigit(board[x][y])) {
                    if (hash_map[1][board[x][y] - '0'])
                        return false;
                    hash_map[1][board[x][y] - '0']++;
                }

            }
        }
        memset(hash_map, 0, sizeof(hash_map));

        for (uint8_t y = 0; y < 9; y += 3) {
            for (uint8_t x = 0; x < 9; x++) {
                if (!(x % 3))
                    memset(hash_map, 0, sizeof(hash_map));
                if (isdigit(board[y][x])) {
                    if (hash_map[0][board[y][x] - '0'])
                        return false;
                    hash_map[0][board[y][x] - '0']++;
                }
                if (isdigit(board[y + 1][x])) {
                    if (hash_map[0][board[y + 1][x] - '0'])
                        return false;
                    hash_map[1][board[y + 1][x] - '0']++;
                }
                if (isdigit(board[y + 2][x])) {
                    if (hash_map[0][board[y + 2][x] - '0'])
                        return false;
                    hash_map[2][board[y + 2][x] - '0']++;
                }
            }
        }

        return true;
    }
};

int main() {
	Solution sl;

    vector<vector<char>> sudoku = {
    {'.','.','.','.','5','.','.','1','.'},
    {'.','4','.','3','.','.','.','.','.'},
    {'.','.','.','.','.','3','.','.','1'},
    {'8','.','.','.','.','.','.','2','.'},
    {'.','.','2','.','7','.','.','.','.'},
    {'.','1','5','.','.','.','.','.','.'},
    {'.','.','.','.','.','2','.','.','.'},
    {'.','2','.','9','.','.','.','.','.'},
    {'.','.','4','.','.','.','.','.','.'}};


	sl.isValidSudoku(sudoku);
}
