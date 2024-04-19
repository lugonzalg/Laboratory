from typing import List

class Solution:

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        occurence = {}
        ans = []

        for num in nums:
            occurence[num] = 1 + occurence.get(num, 0)

        occurence = sorted(occurence.items(),
                        key=lambda kv: kv[1],
                        reverse=False)
        for _ in range(k):
            ans.append(occurence.pop()[0])
        return ans

def main():

    sl = Solution()

    retval = sl.topKFrequent([1,1,1,2,2,3], 2)
    print(f"Result: {retval}")

if __name__ == "__main__":
    main()