# The isBadVersion API is already defined for you.
def isBadVersion(version: int) -> bool:
    return version != 4

class Solution:
    #leetcode
    def firstBadVersion(self, n: int) -> int:

        low, high = 1, n

        while low <= high:

            mid = low + ((high - low) // 2)

            if isBadVersion(mid):
                high = mid - 1
            else:
                low = mid + 1

        return low


    #me
    #def firstBadVersion(self, n: int) -> int:

    #    low, high = 0, n

    #    while low <= high:

    #        mid = low + ((high - low) // 2)

    #        ans_1 = isBadVersion(mid)
    #        ans_2 = isBadVersion(mid + 1)

    #        if not ans_1 and ans_2:
    #            return mid + 1
    #        elif not ans_1:
    #            low = mid + 1
    #        else:
    #            high = mid - 1

    #    return mid + 1

def main() -> int:
    sl = Solution()

    n = 5
    print(f"ans 1: {sl.firstBadVersion(n)}")

if __name__ == "__main__":
    main()