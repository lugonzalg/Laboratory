class Solution:
    def guessNumber(self, n: int) -> int:

        low, high = 0, 2147483647
        while True:

            mid = low + ((high - low) // 2)
            retval = guess(mid)

            if retval == 0:
                break
            elif retval == -1:
                high = mid - 1
            else:
                low = mid + 1

        return mid
        