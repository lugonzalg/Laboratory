import math
from typing import Optional
from dataclasses import dataclass

# Definition for singly-linked list.
@dataclass
class ListNode:

    val: int
    next: None = None

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:

        #find the middle of the list
        fast,slow = head.next, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        #reverse the second mid
        second = slow.next
        prev = slow.next = None
        while second:
            tmp = second.next
            second.next = prev

            prev = second
            second = tmp

        first, second = head, prev
        while second:

            tmp, tmp2 = first.next, second.next
            first.next = second
            second.next = tmp

            first, second = tmp, tmp2

        return head

        #curr = head
        #list_len = 0

        #while curr:
        #    curr = curr.next
        #    list_len += 1

        #median = math.ceil(list_len / 2)
        #back_head = head

        #for n in range(median):
        #    back_head = back_head.next

        #prevNode = None
        #while back_head:

        #    currNode = back_head
        #    back_head = back_head.next

        #    currNode.next = prevNode
        #    prevNode = currNode

        #back_head = prevNode
        #prev = None
        #ref = head
        #while head:
        #    nextNode = head.next
        #    head.next = back_head

        #    if back_head is None:
        #        nextNode2 = None
        #    else:
        #        nextNode2 = back_head.next
        #        back_head.next = nextNode

        #    head = nextNode
        #    back_head = nextNode2

        #print(back_head)
        #print(list_len)
        """
        Do not return anything, modify head in-place instead.
        """

def main() -> int:

    sl = Solution()

    head = ListNode(1)
    curr = head
    for n in range(2, 6):
        curr.next = ListNode(n)
        curr = curr.next

    sl.reorderList(head)
    while head:
        print(head.val)
        head = head.next

if __name__ == "__main__":
    main()