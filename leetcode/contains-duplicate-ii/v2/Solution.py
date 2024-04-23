from typing import List

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:

        hash_map = {}

        for idx, num in enumerate(nums):

            if num in hash_map:
                if abs(hash_map[num] - idx) <= k:
                    return True
            hash_map[num] = idx
        return False
        #n = len(nums)
        
        #for l in range(n - k + 1):

        #    for r in range(l + 1, len(nums)):

        #        if abs(l - r) > k:
        #            break

        #        if nums[l] == nums[r]:
        #            if abs(l - r) <= k:
        #                return True
        #return False

def main() -> int:

    sl = Solution()

    nums = [99,99]
    k = 2
    print(f"ans 1: {sl.containsNearbyDuplicate(nums, k)}")

    nums = [1,2,3,1]
    k = 3

    print(f"ans 1: {sl.containsNearbyDuplicate(nums, k)}")

    nums = [1,0,1,1]
    k = 1
    print(f"ans 2: {sl.containsNearbyDuplicate(nums, k)}")

    nums = [1,2,3,1,2,3]
    k = 2
    print(f"ans 3: {sl.containsNearbyDuplicate(nums, k)}")

if __name__ == "__main__":
    main()