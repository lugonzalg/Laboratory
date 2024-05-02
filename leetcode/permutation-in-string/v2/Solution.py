from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        count_s1 = Counter(s1)
        print(count_s1)
        #map_s = {}
        #len_s = len(s1)
        #r = l = 0

        ##create map of chars
        #for char in s1:
        #    map_s[char] = 1 + map_s.get(char, 0)

        #while l < len(s2):

        #    char_count = map_s.get(s2[l], 0)

        #    #iterate over left until map char found
        #    if char_count == 0:
        #        l += 1
        #        continue

        #    #move right pointer to left pointer pos
        #    r = l
        #    while r < len(s2) and map_s.get(s2[r]):
        #        map_s[s2[r]] -= 1
        #        len_s -= 1
        #        r += 1

        #    if len_s <= 0:
        #        return True
        #    elif r == len(s2[r]):
        #        return False

        #    while l < r and r < len(s2) and not map_s.get(s2[r]):
        #        map_s[s2[l]] = 1 + map_s.get(s2[l])
        #        len_s += 1
        #        l += 1
        #return False

def main() -> int:
    
    sl = Solution()

    s1 = "ab"
    s2 = "eidbaooo"

    print(f"ans 1: {sl.checkInclusion(s1, s2)}")

    s2 = "eidboaooo"
    print(f"ans 2: {sl.checkInclusion(s1, s2)}")

    s1 = "adc"
    s2 = "dcda"
    print(f"ans 3: {sl.checkInclusion(s1, s2)}")

    s1 = "hello"
    s2 = "ooolleoooleh"
    print(f"ans 4: {sl.checkInclusion(s1, s2)}")

    s1 = "ky"
    s2 = "ainwkckifykxlribaypk"
    print(f"ans 5: {sl.checkInclusion(s1, s2)}")

    s1 = "ccc"
    s2 = "cbac"
    print(f"ans 6: {sl.checkInclusion(s1, s2)}")

if __name__ == "__main__":
    main()