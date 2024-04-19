class Solution:
    def isPalindrome(self, s: str) -> bool:

        s = ''.join([c.lower() for c in s if c.isalnum()])
        l, r = 0, len(s) - 1
        while l < r:

            if s[r].lower() != s[l].lower():
                return False
            
            l += 1
            r -= 1
        
        return True

    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1

        while l < r:

            if ".: ,".find(s[l]) != -1:
                l += 1
                continue

            elif ".: ,".find(s[r]) != -1:
                r -= 1
                continue

            elif s[r].lower() != s[l].lower():
                return False
            
            l += 1
            r -= 1
        return True

def main():

    sl = Solution()

    retval = sl.isPalindrome("A man, a plan, a canal: Panama")
    print(retval)

if __name__ == "__main__":

    main()