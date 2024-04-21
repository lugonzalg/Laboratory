from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:

        ans = left = 0
        right = len(height) - 1

        while left < right:

            area = (right - left) * min(height[right], height[left])
            ans = max(area, ans)

            if height[right] >= height[left]:
                left += 1
            else:
                right -= 1

        return ans


def main() -> int:

    sl = Solution()

    nums = [1,8,6,2,5,4,8,3,7]
    nums2 = [1,1]

    print(f"retval 1: {sl.maxArea(nums)}")
    print(f"retval 2: {sl.maxArea(nums2)}")

if __name__ == "__main__":
    main()