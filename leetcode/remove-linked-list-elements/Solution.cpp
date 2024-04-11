/**
 * Definition for singly-linked list.
 * */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *tmp, *prev, *head_ref;

        while (head and head->val == val) {
            tmp = head;
            head = head->next;
            delete tmp;
        }

        head_ref = head; //detalle 1
        prev = head;
        while (head) {

            if (head->val == val) {

                prev->next = head->next;
                tmp = head;
                head = head->next;
                delete tmp;
            } else {
                
                prev = head; //detalle 2
                head = head->next;

            }
        }

        return head_ref;
    }
};