/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;
using std::sort;
using std::cout;
using std::endl;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    TreeNode* _create_BST(vector<int>& nums, int start, int end) {
        int mid;
        TreeNode *node;

        if (start > end)
            return nullptr;

        mid = start + (end - start) / 2;

        node = new TreeNode(nums[mid]);
        node->left = this->_create_BST(nums, start, mid - 1);
        node->right = this->_create_BST(nums, mid + 1, end);
        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return this->_create_BST(nums, 0, nums.size() - 1);
    }
};

int main() {

    Solution sl;
    vector<int> v = {-10, -3, 0, 5, 9};

    sl.sortedArrayToBST(v);
    return 0;
}