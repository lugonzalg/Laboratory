class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        char_map = {}
        max_count = max_len = l = char_count = r = 0

        while r < len(s):
            char_count = char_map.get(s[r], 0)
            max_count = max(char_count, max_count)

            if r - l - max_count > k:

                char_map[s[l]] -= 1
                l += 1
            
            else:

                max_len = max(max_len, r - l + 1)
                char_map[s[r]] = 1 + char_map.get(s[r], 0)
                r += 1

        return max_len

def main() -> int:

    sl = Solution()

    s = "ABAB"
    k = 2

    print(f"ans 1: {sl.characterReplacement(s, k)}")

    s = "AABABBA"
    k = 1
    print(f"ans 1: {sl.characterReplacement(s, k)}")

    s = "BAAAB"
    k = 2
    print(f"ans 1: {sl.characterReplacement(s, k)}")

if __name__ == "__main__":
    main()