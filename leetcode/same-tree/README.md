100. Same Tree
Easy
Topics
Companies

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:

Input: p = [1,2,1], q = [1,1,2]
Output: false

 

Constraints:

    The number of nodes in both trees is in the range [0, 100].
    -104 <= Node.val <= 104

Algorithm:

I will trasverse both tree in paralell, if there is any difference, return false, otherwise return true.

I have a tree, I only want to trasverse it, good, the function is:

_trasverse_tree(node)

    if node is nullptr
        return false

    trasverse_tree(node.left)
    trasverse_tree(node.right)

what if I want to trasverse 2 or n trees? I have to check that both nodes
exist have the same state they exist or not and they have the same value.

_search(tree1, tree2)

    if tree1 and tree2 and diff(tree1.val, tree2.val):
        return false
    else if tree1 == nullptr and tree2 != nullptr or tree1 != nullptr and tree2 == nullptr
        return false

    _trasverse(tree1.left, tree2.left)
    _trasverse(tree1.right, tree2.right)

BAD APPROACH

Algorithm2 (leetcode solution):

_trasverse t1, t2:

    check t1 == null and t2 == null
        return true

    check t1 and t2 and t1.val == t2.val
        return _trasverse(t1.left, t1.left) == _trasverse(t1.right, t1.right) 

    return false