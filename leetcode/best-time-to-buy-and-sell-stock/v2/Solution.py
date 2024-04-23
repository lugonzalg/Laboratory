from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        l, r, n, ans = 0, 1, len(prices), 0

        while r < n:

            if prices[l] > prices[r]:
                l = r
                r += 1
                continue
        
            ans = max(ans, prices[r] - prices[l])
            r += 1
        return ans

def main() -> int:

    sl = Solution()

    prices = [7,1,5,3,6,4]
    print(f"ans 1: {sl.maxProfit(prices)}")

if __name__ == "__main__":
    main()