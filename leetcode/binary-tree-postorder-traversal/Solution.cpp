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

    void _trasverse_postorder(TreeNode* root, vector<int> &v) {

        if (root == nullptr)
            return ;

        this->_trasverse_postorder(root->left, v);    
        this->_trasverse_postorder(root->right, v);    
        v.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        this->_trasverse_postorder(root, ans);
        return ans;
    }
};