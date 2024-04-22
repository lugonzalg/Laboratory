from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:

        low, high = 0, len(nums) - 1
        ans = float("inf")

        while low <= high:

            mid = low + ((high - low) // 2)

            if nums[mid] > nums[high]:
                low = mid + 1
            else:
                high = mid - 1
                ans = min(ans, nums[mid])
        return min(ans, nums[mid])

def main() -> int:

    sl = Solution()

    nums = [3,4,5,1,2]
    print(f"ans 1: {sl.findMin(nums)}")

    nums = [3,1,2]
    print(f"ans 1: {sl.findMin(nums)}")

if __name__ == "__main__":
    main()