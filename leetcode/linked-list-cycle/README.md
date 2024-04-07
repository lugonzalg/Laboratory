141. Linked List Cycle
Easy
Topics
Companies

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

 

Constraints:

    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.

Algorithm(wrong):

I will create a unordered map of values, store each and increment by 1. If there is
a key: val of x: 1 then return True, otherwise return False.

Reevaluation:

Instead of selecting the repeated value, store the address. Very slow.

Algorithm 2 (leetcode answer):

Iterate over the list with two pointer, one will go 1 by 1 and the other 2 by 2.
If there is a cycle they both will end up being the same value.

Simplicity wins always over complexity. Brilliant.