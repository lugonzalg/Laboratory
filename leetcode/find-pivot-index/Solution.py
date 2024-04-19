from typing import List

#https://www.youtube.com/watch?v=u89i60lYx8U
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)

        left_sum = 0
        for idx, num in enumerate(nums):

            right_sum = total - left_sum - num
            if right_sum == left_sum:
                return idx
            left_sum += num
        return -1

    #def pivotIndex(self, nums: List[int]) -> int:
        #l, r = 0, len(nums) - 1
        #l_acc = r_acc = 0

        #while l != r:

            #if r_acc <= l_acc:
               #r_acc += nums[r]
               #r -= 1
            #else:
               #l_acc += nums[l]
               #l += 1
          
        #if l_acc != r_acc:
            #return -1
        #return l

def main():
 
    sl = Solution()

    print(f"Solution: {sl.pivotIndex([1,7,3,6,5,6])}")
    print(f"Solution: {sl.pivotIndex([1,2,3])}")
    print(f"Solution: {sl.pivotIndex([-1,-1,-1,-1,-1,0])}")

if __name__ == "__main__":
    main()