# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from typing import Optional

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = fast = head

        while fast and fast.next:

            slow = slow.next
            fast = fast.next.next

        return slow

def main() -> int:

    sl = Solution()

    head = None
    print(f"ans 1: {sl.middleNode(head)}")

if __name__ == "__main__":
    main()