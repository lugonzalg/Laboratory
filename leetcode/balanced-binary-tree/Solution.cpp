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

    int maxDepth(TreeNode *root) {

        int left, right;

        if (root == nullptr)
            return 0;

        left = this->maxDepth(root->left);
        right = this->maxDepth(root->right);
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        int diff, left, right;

        if (root == nullptr)
            return true;

        left = this->maxDepth(root->left);
        right = this->maxDepth(root->right);
        if (abs(left - right) > 1)
            return false;

        return isBalanced(root->left) and isBalanced(root->right);
    }
};