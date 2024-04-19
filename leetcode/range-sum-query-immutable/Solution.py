from typing import List

class NumArray:

    class NumArray:

    def __init__(self, nums: List[int]):

        self.nums = [0] * len(nums)
        accumulate = 0

        for idx, num in enumerate(nums):

            accumulate += nums[idx]
            self.nums[idx] = accumulate
        

    def sumRange(self, left: int, right: int) -> int:

        if left == 0:
            return self.nums[right]
        return self.nums[right] - self.nums[left - 1]

    #def __init__(self, nums: List[int]):

    #    self.nums = nums.copy()
    #    

    #def sumRange(self, left: int, right: int) -> int:

    #    total = 0
    #    for idx in range(left, right + 1):
    #        total += self.nums[idx]

    #    return total

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)