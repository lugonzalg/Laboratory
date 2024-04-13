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
    bool isPalindrome(ListNode* head) {

        vector<int> v;
        size_t n, mid;

        while (head) {
            v.push_back(head->val);
            head = head->next;
        }

        n = v.size() - 1;
        mid = n / 2;

        for (size_t idx = 0; idx <= mid; idx++) {
            if (v[idx] != v[n - idx])
                return false;
        }

        return true;
    }
};
