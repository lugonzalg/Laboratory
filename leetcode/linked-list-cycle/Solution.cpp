/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_map>

using std::unordered_map;

class ListNode;

/*
class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<int, int> uom;

        while (head) {

            if (!uom[head->val])
                uom[head->val]++;
            else
                return true;
            head = head->next;

        }
        return false;
    }
};
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *slow = head;
        ListNode *fast;
        
        if (slow == nullptr)
            return false;
            
        fast = head->next;

        while (slow != fast) {
            if (fast == nullptr or fast->next == nullptr)
                return false;
            slow = slow->next;    
            fast = fast->next->next;    
        }
        return true;
    }
};