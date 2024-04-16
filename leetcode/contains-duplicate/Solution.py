from typing import List
import time

class Solution:

    def BRUTE_FORCE_containsDuplicate(self, nums: List[int]) -> bool:

        for idx, num in enumerate(nums):

            for key in nums[idx + 1:]:
                if key == num:
                    return True

        return False

    def SET_V1_HASH_MAP_containsDuplicate(self, nums: List[int]) -> bool:

        num_set = set()

        for num in nums:

            if num in num_set:
                return True
            num_set.add(num)
        return False

    def SET_V2_HASH_MAP_containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) == len(set(nums))
 
    def HASH_MAP_containsDuplicate(self, nums: List[int]) -> bool:

        num_check = {}

        for num in nums:
            
            if num_check.get(num) is None:
                num_check[num] = 1
            else:
                return True
        return False
    
def main():

    sl = Solution()
    nums = [1,2,3,4,1]

    ref = time.time()
    #print(f"Answer: {sl.BRUTE_FORCE_containsDuplicate(nums)} - elapsed: {time.time() - ref}")
    print(f"Answer: {sl.SET_V1_HASH_MAP_containsDuplicate(nums)} - elapsed: {time.time() - ref}")
    ref = time.time()
    #print(f"Answer: {sl.HASH_MAP_containsDuplicate(nums)} - elapsed: {time.time() - ref}")
    print(f"Answer: {sl.SET_V2_HASH_MAP_containsDuplicate(nums)} - elapsed: {time.time() - ref}")

    nums = [x for x in range(10000)]
    ref = time.time()
    print(f"Answer: {sl.SET_V1_HASH_MAP_containsDuplicate(nums)} - elapsed: {time.time() - ref}")
    #print(f"Answer: {sl.BRUTE_FORCE_containsDuplicate(nums)} - elapsed: {time.time() - ref}")
    ref = time.time()
    print(f"Answer: {sl.SET_V2_HASH_MAP_containsDuplicate(nums)} - elapsed: {time.time() - ref}")
    #print(f"Answer: {sl.HASH_MAP_containsDuplicate(nums)} - elapsed: {time.time() - ref}")


if __name__ == '__main__':
    main()