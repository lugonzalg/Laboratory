# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from typing import Optional

class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        fast = slow = head
        sums = []

        while fast and fast.next:

            sums.append(slow.val)

            slow = slow.next
            fast = fast.next.next

        idx = len(sums) - 1
        maxv = 0
        while slow:

            maxv = max(maxv, sums[idx] + slow.val)
            slow = slow.next
            idx -= 1

        return maxv

def main() -> int:

    sl = Solution()
    node5 = ListNode(5)
    node4 = ListNode(4)
    node5.next = node4
    node2 = ListNode(2)
    node4.next = node2
    node1 = ListNode(1)
    node2.next = node1

    head = node5
    print(f"ans 1: {sl.pairSum(head)}")

if __name__ == "__main__":
    main()