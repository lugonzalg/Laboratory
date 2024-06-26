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

    bool _flag = false;

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        
        targetSum -= root->val;
        if (targetSum == 0)
            return true;

        return hasPathSum(root->left, targetSum) or hasPathSum(root->left, targetSum);
    }
};