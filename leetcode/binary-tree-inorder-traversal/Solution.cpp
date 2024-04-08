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

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class TreeNode;

class Solution {

    vector<int> _v;

public:
    void _inorder(TreeNode *node) {

        if (node->left != nullptr)
            this->_inorder(node->left);

        this->_v.push_back(node->val);

        if (node->rigth != nullptr)
            this->_inorder(node->rigth);

    }

    vector<int> inorderTraversal(TreeNode* root) {

        if (root == nullptr)
            return this->_v;

        this->_inorder(root);
        return this->_v;
    }
};