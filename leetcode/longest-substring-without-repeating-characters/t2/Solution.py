import time

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        l = ans = 0
        char_set = set()

        for r in range(len(s)):

            while s[r] in char_set:
                char_set.remove(s[l])
                l += 1

            char_set.add(s[r])
            ans = max(ans, r - l + 1)

        return ans

    def lengthOfLongestSubstring2(self, s: str) -> int:

        l = r = ans = 0
        letters = set()

        while r < len(s):

            if s[r] in letters:
                ans = max(ans, r - l)
                l += 1
                r = l
                letters.clear()
            else:
                letters.add(s[r])
                r += 1

        return max(ans, r - l)

def compare(s: str, sl: Solution):

    ref = time.time()

    print(f"ans 1: {sl.lengthOfLongestSubstring(s)}")
    print(f"elapsed time 1: {time.time() - ref}")

    ref = time.time()
    print(f"ans 5: {sl.lengthOfLongestSubstring2(s)}")

    print(f"elapsed time 2: {time.time() - ref}")
    print()

def main() -> int:

    sl = Solution()

    s = "pwwkew"
    compare(s, sl)
    s = "bbbbb"
    compare(s, sl)
    s = "abcabcbb"
    compare(s, sl)
    s = " "
    compare(s, sl)
    s = "dvdf"
    compare(s, sl)
    s = "sajfhiasodhfiurhiauhsdfuahwaushdfb,mfrioqoeiqwertyuik;la"
    compare(s, sl)

if __name__ == "__main__":
    main()