/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* headA, ListNode* headB) {

        ListNode* headMerge = nullptr;
        ListNode* ref = nullptr;

        if (headA and headB) {
            if (headA->val <= headB->val) {
                headMerge = headA;
                ref = headMerge;
                headA = headA->next;
            }
            else if (headB->val <= headA->val) {
                headMerge = headB;
                ref = headMerge;
                headB = headB->next;
            }
        }
        else if (headA) {
            headMerge = headA;
            ref = headMerge;
            headA = headA->next;
        }
        else if (headB) {
            headMerge = headB;
            ref = headMerge;
            headB = headB->next;
        }

        while (headA || headB) {

            if (headA and headB) {
                if (headA->val <= headB->val) {
                    ref->next = headA;
                    headA = headA->next;
                    ref = ref->next;
                }
                else if (headB->val <= headA->val) {
                    ref->next = headB;
                    headB = headB->next;
                    ref = ref->next;
                }
            }
            else if (headA) {
                ref->next = headA;
                headA = headA->next;
                ref = ref->next;
            }
            else if (headB) {
                ref->next = headB;
                headB = headB->next;
                ref = ref->next;
            }
        }

        return headMerge;
    }
};
