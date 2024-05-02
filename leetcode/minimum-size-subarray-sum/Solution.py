from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        n = len(nums)
        total = l = r = 0
        min_len = n + 1

        while r < n:

            if total < target:
                total += nums[r]
                r += 1
            else:
                min_len = min(min_len, r - l)
                total -= nums[l]
                l += 1

        for l in range(l, n):

            if total >= target:
                min_len = min(min_len, r - l)
                total -= nums[l]

        if min_len == n + 1:
            return 0
        return min_len

        #n = len(nums)

        #if n == 1:
        #    return 0
        
        #min_size = n + 1
        #l = 0
        #total = nums[0]

        #for r in range(1, n):

        #    total += nums[r]

        #    if total >= target:
        #        
        #        print(f" arr: {nums[l:r + 1]} = {total}")
        #        total -= nums[l]
        #        min_size = min(min_size, r - l + 1)
        #        l += 1
        
        #for l in range(l, n):

        #    total -= nums[l]
        #    if total >= target:
        #        min_size = min(min_size, r - l)


        #if min_size == n + 1:
        #    return 0
        #return min_size


def main() -> int:
    sl = Solution()

    t = 7
    nums = [2,3,1,2,4,3]

    print(f"ans 1: {sl.minSubArrayLen(t, nums)}")

    t = 4
    nums = [1,4,4]
    print(f"ans 1: {sl.minSubArrayLen(t, nums)}")

    t = 11
    nums = [1,1,1,1,1,1,1,1]
    print(f"ans 1: {sl.minSubArrayLen(t, nums)}")

if __name__ == "__main__":
    main()