from typing import List

class Solution:

    def removeDuplicates(self, nums: List[int]) -> int:

        n = len(nums)

        if n < 3:
            return n
        
        left = 2

        for right in range(2, n):

            if nums[right] != nums[left - 2]:
                nums[left] = nums[right]
                left += 1

        print(nums)
        return left

        #r = l = 1
        #n = len(nums)

        #if n == 1:
        #    return 1

        #if nums[0] == nums[1]:
        #    l = r = 2

        #while r < len(nums):

        #    if nums[r] != nums[r - 1]:
        #        nums[l] = nums[r]
        #        l += 1

        #        if r + 1 < len(nums) and nums[r] == nums[r + 1]:
        #            nums[l] = nums[r + 1]
        #            r += 1
        #            l += 1

        #    r += 1

        #return l

def main() -> int:

    sl = Solution()

    nums = [1,1,1,2,2,3]
    retval = sl.removeDuplicates(nums)
    print(f"Result: {retval}")

if __name__ == "__main__":
    main()