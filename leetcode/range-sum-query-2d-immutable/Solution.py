from typing import List

#src: https://github.com/neetcode-gh/leetcode/blob/main/python/0304-range-sum-query-2d-immutable.py

class NumMatrix:

    def __init__(self, matrix: List[List[int]]):

        self.matrix = [[0] * (len(matrix[0]) + 1) for _ in range(len(matrix) + 1)]

        for y, line in enumerate(matrix):
            prev = 0
            for x, num in enumerate(line):
                prev += num
                above = self.matrix[y][x + 1]
                self.matrix[y + 1][x + 1] = prev + above

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        sum_col2 = self.sum_[row2 + 1][col2 + 1] - self.sum_[row1][col2 + 1]
        sum_col1 = self.sum_[row2 + 1][col1] - self.sum_[row1][col1]

        return sum_col2 - sum_col1        


    #def __init__(self, matrix: List[List[int]]):

    #    x_len = len(matrix[0])
    #    y_len = len(matrix)
    #    self.matrix = [[0] * x_len for _ in range(y_len)]

    #    for y, row in enumerate(matrix):

    #        x_accumulate = 0
    #        y_accumulate = 0
    #        for x, _ in enumerate(row):
    #            x_accumulate += matrix[y][x]
    #            self.matrix[y][x] += x_accumulate
    #            print(matrix[y][x], end=' ')
    #        print()

    #def print_matrix(self):

    #    print("MATRIX")
    #    for row in self.matrix:
    #        for num in row:
    #            print(num, end=' ')
    #        print()
    #    print()

    #def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
    #    pass

def main() -> int:

    llist = [[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]

    for row in llist:
        for num in row:
            print(num, end=' ')
        print()
    print()
    nm = NumMatrix(llist)
    nm.print_matrix()

if __name__ == "__main__":
    main()

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)