class Node:

    def __init__(self, val: int, min_val: int, next_node = None):

        self.val = val
        self.min_val = min_val
        self.next = next_node

class MinStack:

    def __init__(self):
        self.stack = None

    def push(self, val: int) -> None:

        if self.stack is None:
            self.stack = Node(val, val)
        else:
            min_val = min(val, self.stack.min_val)
            self.stack = Node(val, min_val, self.stack)

    def pop(self) -> None:
        node = self.stack
        self.stack = self.stack.next
        del node

    def top(self) -> int:
        return self.stack.val

    def getMin(self) -> int:
        return self.stack.min_val

def main() -> int:

    minStack = MinStack()
    minStack.push(-2)
    minStack.push(0)
    minStack.push(-3)
    print(f"min: {minStack.getMin()}")
    minStack.pop()
    print(f"minStack.top()")
    print(f"min: {minStack.getMin()}")

if __name__ == "__main__":
    main()

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()