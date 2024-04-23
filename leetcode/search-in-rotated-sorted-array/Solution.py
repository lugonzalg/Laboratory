from typing import List

class Solution:
class Solution:
    def search(self, nums: List[int], target: int) -> int:

        low, high = 0, len(nums) - 1

        while low <= high:

            mid = low + ((high - low) // 2)

            if nums[mid] == target:
                return mid

            if nums[low] <= nums[mid]:
            
                if nums[mid] < target or nums[low] > target:
                    low = mid + 1
                else:
                    high = mid - 1

            else:
                if nums[mid] > target or nums[high] < target:
                    high = mid - 1
                else:
                    low = mid + 1

        return -1

    #def search(self, nums: List[int], target: int) -> int:

    #    low, high = 0, len(nums) - 1

    #    while low <= high:

    #        mid = low + ((high - low) // 2)

    #        if nums[mid] == target:
    #            return mid

    #        #The target is lower, is on the left
    #        if nums[mid] > target:
    #            #The target is on the left
    #            if nums[low] <= target:
    #                high = mid - 1
    #            #The target is on the right
    #            else:
    #                low = mid + 1

    #        #the target is bigger, is on the right
    #        elif nums[mid] < target:
    #            if nums[high] <= target:
    #                low = mid + 1
    #            else:
    #                high = mid - 1

    #    return -1

def main() -> int:

    sl = Solution()

    nums = [4,5,6,7,0,1,2]
    target = 4
    #print(f"ans 1: {sl.search(nums, target)}")
    target = 0
    #print(f"ans 2: {sl.search(nums, target)}")

    nums = [1,3]
    target = 3
    #print(f"ans 3: {sl.search(nums, target)}")

    nums = [5,1,3]
    target = 3
    print(f"ans 4: {sl.search(nums, target)}")

if __name__ == "__main__":
    main()