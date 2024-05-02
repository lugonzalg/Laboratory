from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:

        n = len(arr)

        if n < k:
            return 0

        count = l = 0
        avg = sum(arr[:k - 1])

        for r in range(k - 1, n):
            avg += arr[r]

            if avg / k >= threshold:
                count += 1

            avg -= arr[l]
            l += 1

        return count

def main() -> int:

    sl = Solution()

    nums = [2,2,2,2,5,5,5,8]
    k = 3
    th = 4
    print(f"ans 1: {sl.numOfSubarrays(nums, k, th)}")

if __name__ == "__main__":
    main()