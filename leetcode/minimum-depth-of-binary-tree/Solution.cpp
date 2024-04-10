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

class Solution {

    int _minDepth(TreeNode *root) {

        if (root == nullptr)
            return 0;
        
        if (root->left == nullptr and root->right == nullptr)
            return 1;
        
        if (root->left == nullptr)
            return _minDepth(root->right) + 1;

        if (root->right == nullptr)
            return _minDepth(root->left) + 1;
        

        return min(_minDepth(root->left), _minDepth(root->right)) + 1;
    }

public:
    int minDepth(TreeNode* root) {
        return _minDepth(root);
    }
};