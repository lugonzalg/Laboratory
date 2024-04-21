from typing import List

class Solution:

    def twoSum(self,
               start: int, right: int,
               nums: List[int], ans: List[int]) -> None:

        left = start + 1

        while left < right:

            calc = nums[start] + nums[left] + nums[right]
            if calc == 0:
                ans.append([nums[start], nums[left], nums[right]])

            if calc < 0:
                left += 1
                while left < right and nums[left] == nums[left - 1]:
                    left += 1
            else:
                right -= 1
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1

    def threeSum(self, nums: List[int]) -> List[List[int]]:

        ans = []
        nums.sort()
        n = len(nums)

        for idx in range(n - 2):

            if idx and nums[idx] == nums[idx - 1]:
                continue
            self.twoSum(idx, n - 1, nums, ans)
        
        return ans
        


def main() -> int:

    sl = Solution()

    nums = [-1,0,1,2,-1,-4]
    print(f"ans: {sl.threeSum(nums)}")
    nums = [0,0,0,0]
    print(f"ans: {sl.threeSum(nums)}")

if __name__ == "__main__":
    main()