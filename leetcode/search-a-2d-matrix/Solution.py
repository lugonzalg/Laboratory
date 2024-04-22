from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        low, high = 0, len(matrix) - 1

        while low <= high:

            mid = low + ((high - low) // 2)

            if matrix[mid][0] > target:
                high = mid - 1
            elif matrix[mid][-1] < target:
                low = mid + 1
            else:
                break

        target_row = mid
        low, high = 0, len(matrix[target_row]) - 1

        while low <= high:

            mid = low + ((high - low) // 2)

            if matrix[target_row][mid] > target:
                high = mid - 1
            elif matrix[target_row][mid] < target:
                low = mid + 1
            else:
                return True

        return False

def main() -> int:
    sl = Solution()

    matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
    target = 3

    #print(f"ans 1 {sl.searchMatrix(matrix, target)}")

    matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
    target = 13

    print(f"ans 1 {sl.searchMatrix(matrix, target)}")

if __name__ == "__main__":
    main()