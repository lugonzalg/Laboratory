from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:

        l, r = 0, len(numbers) -1
    
        while l < r:

            total = numbers[l] + numbers[r]

            if total < target:
                l += 1
            elif total > target:
                r -= 1
            else:
                return [l + 1, r + 1]

        return [-1, -1]

def main() -> int:

    sl = Solution()

    retval = sl.twoSum([2,7,11,15], 9)
    print(f"Retval: {retval}")

if __name__ == "__main__":
    main()