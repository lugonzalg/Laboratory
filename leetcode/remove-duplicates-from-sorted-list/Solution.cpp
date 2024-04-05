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

class ListNode;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode *tmp;
        
        for (ListNode *tracer = head; tracer && tracer->next; tracer = tracer->next) {

            while (tracer->next and tracer->val == tracer->next->val) {
                tmp = tracer->next;
                tracer->next = tmp->next;
                delete tmp;
            }
        }
        return head;
        
    }
};