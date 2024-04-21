from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:

        l, r = 0, len(height) - 1
        max_left, max_right = height[l], height[r]
        ans = 0

        while l < r:

            if height[l] <= height[r]:
                res = min(max_left, max_right) - height[l]
                l += 1
                max_left = max(max_left, height[l])

            else:
                res = min(max_left, max_right) - height[r]
                r -= 1
                max_right = max(max_right, height[r])
            
            if res > 0:
                ans += res

        return ans

def main() -> int:

    sl = Solution()

    height_1 = [0,1,0,2,1,0,1,3,2,1,2,1]
    height_2 = [4,2,0,3,2,5]

    print(f"ans 1: {sl.trap(height_1)}")
    print(f"ans 2: {sl.trap(height_2)}")

if __name__ == "__main__":
    main()