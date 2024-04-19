from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        anagrams = {}

        for word in strs:

            sort_word = sorted(word)
            sort_word = ''.join(sort_word)
            if anagrams.get(sort_word):
                anagrams[sort_word].append(word)
            else:
                anagrams[sort_word] = [word]
        return anagrams.values()

def main():

    sl = Solution()

    res = sl.groupAnagrams(["eat","tea","tan","ate","nat","bat"])
    print(f"Result: {res}")

if __name__ == "__main__":
    main()