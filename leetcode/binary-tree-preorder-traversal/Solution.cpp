#include<vector>

using std::vector;

class TreeNode;

class Solution {

    void _trasverse_pre(TreeNode *root, vector<int> &v) {

        if (root == nullptr)
            return ;

        v.push_back(root->val);
        this->_trasverse_pre(root->left, v);
        this->_trasverse_pre(root->right, v);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        this->_trasverse_pre(root, ans);
        return ans;
        
    }
};