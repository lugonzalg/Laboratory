from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        l = 1

        for r in range(1, len(nums)):

            if nums[r] != nums[r - 1]:
                nums[l] = nums[r]
                l += 1
        return l

def main() -> int:
    sl = Solution()

    retval = sl.removeDuplicates([1,1,1,1,2])
    print(f"retval: {retval}")
    retval = sl.removeDuplicates([0,0,1,1,1,2,2,3,3,4])
    print(f"retval: {retval}")
    retval = sl.removeDuplicates([1,2])
    print(f"retval: {retval}")

if __name__ == "__main__":
    main()