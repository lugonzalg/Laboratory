from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        vertical_set = set()
        horizontal_set = set()
        local_set = set()
        n = len(board)

        for y in range(n):

            vertical_set.clear()
            horizontal_set.clear()
            for x in range(n):

                if board[y][x] in horizontal_set:
                    return False
                if board[x][y] in vertical_set:
                    return False

                if board[y][x] != '.':
                    horizontal_set.add(board[y][x])

                if board[x][y] != '.':
                    vertical_set.add(board[x][y])

        for y in range(0, n, 3):

            local_set.clear()
            for x in range(0, n):

                if x % 3 == 0:
                    local_set.clear()

                if board[y][x] in local_set:
                    return False
                if board[y + 1][x] in local_set:
                    return False
                if board[y + 2][x] in local_set:
                    return False

                if board[y][x] != '.':
                    local_set.add(board[y][x])
                if board[y + 1][x] != '.':
                    local_set.add(board[y + 1][x])
                if board[y + 2][x] != '.':
                    local_set.add(board[y + 2][x])


        return True

def main():

    sl = Solution()

    sudoku = [["5","3",".",".","7",".",".",".","."]
            ,["6",".",".","1","9","5",".",".","."]
            ,[".","9","8",".",".",".",".","6","."]
            ,["8",".",".",".","6",".",".",".","3"]
            ,["4",".",".","8",".","3",".",".","1"]
            ,["7",".",".",".","2",".",".",".","6"]
            ,[".","6",".",".",".",".","2","8","."]
            ,[".",".",".","4","1","9",".",".","5"]
            ,[".",".",".",".","8",".",".","7","9"]]

    sudoku_v2 = [["8","3",".",".","7",".",".",".","."]
                ,["6",".",".","1","9","5",".",".","."]
                ,[".","9","8",".",".",".",".","6","."]
                ,["8",".",".",".","6",".",".",".","3"]
                ,["4",".",".","8",".","3",".",".","1"]
                ,["7",".",".",".","2",".",".",".","6"]
                ,[".","6",".",".",".",".","2","8","."]
                ,[".",".",".","4","1","9",".",".","5"]
                ,[".",".",".",".","8",".",".","7","9"]]

    sudoku_v3 = [[".",".",".",".","5",".",".","1","."]
                 ,[".","4",".","3",".",".",".",".","."]
                 ,[".",".",".",".",".","3",".",".","1"]
                 ,["8",".",".",".",".",".",".","2","."]
                 ,[".",".","2",".","7",".",".",".","."]
                 ,[".","1","5",".",".",".",".",".","."]
                 ,[".",".",".",".",".","2",".",".","."]
                 ,[".","2",".","9",".",".",".",".","."]
                 ,[".",".","4",".",".",".",".",".","."]]

    sudoku_v4 = [[".",".",".",".","5",".",".","1","."],
                 [".","4",".","3",".",".",".",".","."],
                 [".",".",".",".",".","3",".",".","1"],
                 ["8",".",".",".",".",".",".","2","."],
                 [".",".","2",".","7",".",".",".","."],
                 [".","1","5",".",".",".",".",".","."],
                 [".",".",".",".",".","2",".",".","."],
                 [".","2",".","9",".",".",".",".","."],
                 [".",".","4",".",".",".",".",".","."]]

    print(f"Retval: {sl.isValidSudoku(sudoku)}")
    print(f"Retval: {sl.isValidSudoku(sudoku_v2)}")
    #print(f"Retval: {sl.isValidSudoku(sudoku_v3)}")
    print(f"Retval: {sl.isValidSudoku(sudoku_v4)}")

if __name__ == "__main__":
    main()