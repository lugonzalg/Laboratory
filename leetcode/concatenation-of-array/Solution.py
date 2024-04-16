from typing import List

class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        
        return nums + nums

def main():

    sl = Solution()

    nums = [1,2,3]
    print(f"Answer: {sl.getConcatenation(nums)}")

if __name__ == "__main__":
    main()