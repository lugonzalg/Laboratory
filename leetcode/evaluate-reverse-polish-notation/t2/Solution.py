from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:

        stack = []

        for num in tokens:

            if num in "+-/*":
                first = stack.pop()
                second = stack.pop()
                if num == '+':
                    res = second + first
                elif num == '-':
                    res = second - first
                elif num == '/':
                    res = int(second / first)
                elif num == '*':
                    res = second * first
                stack.append(res)
            else:
                stack.append(int(num))
        return stack.pop()

def main() -> int:

    sl = Solution()

    data = ["2","1","+","3","*"]
    print(f"ans 1: {sl.evalRPN(data)}")
    data = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    print(f"ans 1: {sl.evalRPN(data)}")

if __name__ == "__main__":
    main()