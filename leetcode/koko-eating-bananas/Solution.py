from typing import List
import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        low, high = 1, max(piles)
        ans = high

        while low <= high:
            
            mid = low + ((high - low) // 2)
            hours = 0

            for pile in piles:
                hours += math.ceil(float(pile) / mid)

            if hours <= h:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        return ans
                


def main() -> int:

    sl = Solution()

    piles = [3,6,7,11]
    h = 8
    print(f"ans 1: {sl.minEatingSpeed(piles, h)}")

    piles = [30,11,23,4,20]
    h = 5
    print(f"ans 1: {sl.minEatingSpeed(piles, h)}")
    piles = [30,11,23,4,20]
    h = 6
    print(f"ans 1: {sl.minEatingSpeed(piles, h)}")

if __name__ == "__main__":
    main()