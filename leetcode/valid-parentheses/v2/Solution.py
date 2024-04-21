from typing import List

class Solution:
    def isValid(self, s: str) -> bool:

        stack = []
        parentheses = {
            "}": "{",
            "]": "[",
            ")": "("
        }

        for letter in s:
            
            if letter in "{[(":
                stack.append(letter)
            else:
                if not len(stack):
                    return False
                comp = stack.pop()
                if comp != parentheses[letter]:
                    return False

        if len(stack):
            return False
        return True


def main() -> int:
    sl = Solution()

    data = "()[]{}"
    print(f"ans 1: {sl.isValid(data)}")

if __name__ == "__main__":
    main()