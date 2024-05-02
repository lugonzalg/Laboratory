# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from typing import Optional

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        #prevNode = currNode = None

        #while head:

        #    currNode = head
        #    head = head.next

        #    currNode.next = prevNode
        #    prevNode = currNode

        #return prevNode