from typing import List

class Solution:

    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        ans = []

        def _parentheses_factory(left: int, right: int) -> List[str]:

            if left == right == n:
                ans.append(''.join(stack))
                return

            if left < n:
                stack.append('(')
                _parentheses_factory(left + 1, right)
                stack.pop()
            
            if right < left:
                stack.append(')')
                _parentheses_factory(left, right + 1)
                stack.pop()

        _parentheses_factory(0, 0)
        return ans

def main() -> int:

    sl = Solution()

    n = 2
    print(f"ans 1: {sl.generateParenthesis(n)}")

if __name__ == "__main__":
    main()