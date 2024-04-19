from typing import List
#https://www.youtube.com/watch?v=bNvIQI2wAjk&t=576s

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        new_nums = [0] * n

        prev = 1
        for idx, num in enumerate(nums):
            new_nums[idx] = prev
            prev *= num

        prev = 1
        while (n):
            new_nums[n - 1] *= prev
            prev *= nums[n -1]
            n -= 1

        print(new_nums)

def main():

    sl = Solution()

    print(f"Result: {sl.productExceptSelf([1,2,3,4])}")

if __name__ == "__main__":
    main()