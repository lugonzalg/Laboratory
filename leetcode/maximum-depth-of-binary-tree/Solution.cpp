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

public:

    int maxDepth(TreeNode* root) {

        int left, right;

        if (root == nullptr)
            return 0;

        left = this->maxDepth(root->left);
        right = this->maxDepth(root->right);
        return 1 + max(left, right);
    }
};