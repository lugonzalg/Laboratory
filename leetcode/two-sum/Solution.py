from typing import List
import time

class Solution:
    def HASH_MAP_twoSum(self, nums: List[int], target: int) -> List[int]:

        hash_map = {}

        for idx, num in enumerate(nums):

            retval = hash_map.get(num)
            if retval is None:
                hash_map[target - num] = idx
            else:
                return [retval, idx]
        return [-1, -1]

    def BRUTE_FORCE_twoSum(self, nums: List[int], target: int) -> List[int]:

        n = len(nums)

        for i in range(n):

            for j in range(i + 1, n):

                if nums[i] + nums[j] == target:
                    return [i, j]
        
        return [-1, -1] 

def main() -> int:

    sl = Solution()

    nums = [1,2,3,4,5]
    target = 6
    ref = time.time()

    print(f"Answer: {sl.BRUTE_FORCE_twoSum(nums, target)} - elapsed: {time.time() - ref}")
    ref = time.time()
    print(f"Answer: {sl.HASH_MAP_twoSum(nums, target)} - elapsed: {time.time() - ref}")

if __name__ == "__main__":
    main()