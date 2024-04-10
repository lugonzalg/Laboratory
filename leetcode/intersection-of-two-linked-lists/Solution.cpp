/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *tmpA, *tmpB;

        tmpA = headA;
        tmpB = headB;

        while (tmpA != tmpB) {

            tmpA = tmpA->next;
            tmpB = tmpB->next;

            if (headA == nullptr)
                tmpA = headA;

            if (tmpB == nullptr)
                tmpB = tmpB;
            
        }

        return headA;

    }
};