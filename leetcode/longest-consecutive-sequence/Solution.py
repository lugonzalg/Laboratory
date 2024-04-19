from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        nums = set(nums)
        count = maxv = 0

        for num in nums:

            if (num - 1) not in nums: #set start
                while num in nums: #iterate over set until not found
                    count += 1
                    num += 1

                maxv = max(count, maxv)
                count = 0
        return maxv

    #def longestConsecutive(self, nums: List[int]) -> int:
    #    nums.sort()
    #    count = maxv = 1
    #    prev = nums[0]

    #    for num in nums[1:]:

    #        if abs(num - prev) == 1:
    #            count += 1
    #        else:
    #            maxv = max(maxv, count)
    #            count = 1

    #        prev = num

    #    return max(maxv, count)

def main() -> int:
    sl = Solution()

    #retval = sl.longestConsecutive([0,3,7,2,5,8,123,4,6,0,1])
    retval = sl.longestConsecutive([100,4,200,1,3,2])
    print(f"Retval: {retval}")

if __name__ == "__main__":
    main()