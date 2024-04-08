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
/*
class Solution {

    bool _is_same_tree(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr and t2 == nullptr)
            return true;

        if (t1 and t2 and t1->val == t2->val)
            return _is_same_tree(t1->left, t2->left) and
                _is_same_tree(t1->right, t2->rigth);

        return false;

    }
*/

class Solution {

    bool _is_same_tree(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr and t2 == nullptr)
            return true;

        if (t1 and t2 and t1->val == t2->val)
            return _is_same_tree(t1->left, t2->right) and
                _is_same_tree(t1->right, t2->left);

        return false;

    }

public:
    bool isSymmetric(TreeNode* root) {

        if (root == nullptr)
            return false;

        return _is_same_tree(root->left, root->right);
    }
};