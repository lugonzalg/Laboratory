# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from typing import Optional

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:

        dummy = ListNode(0, head)
        left = dummy
        right = head

        while n and right:
            right = right.next
            n -= 1

        while right:
            left = left.next
            right = right.next

        left.next = left.next.next

        return dummy.next
        #list_len = 0

        #slow, fast = head, head.next
        #while fast and fast.next:
        #    slow = slow.next
        #    fast = fast.next.next
        #    list_len += 2

        #if fast:
        #    list_len += 2
        #else:
        #    list_len += 1

        #print(f"len: {list_len}")
        #print(slow.val)
        #print(fast)

def main() -> int:

    sl = Solution()

    head = ListNode(1)
    #curr = head
    #print(curr.val, end=', ')
    #for n in range(2, 8):
    #    curr.next = ListNode(n)
    #    curr = curr.next
    #    print(curr.val, end=', ')
    #print()

    print(f"ans 1: {sl.removeNthFromEnd(head, 1)}")

if __name__ == "__main__":
    main()