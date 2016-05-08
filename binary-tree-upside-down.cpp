/** NO.156 
	Binary Tree Upside Down

    Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, 
    flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

		For example:
		Given a binary tree {1,2,3,4,5},
		    1
		   / \
		  2   3
		 / \
		4   5
		return the root of the binary tree [4,5,2,#,#,3,1].
		   4
		  / \
		 5   2
		    / \
		   3   1  

    Solution post : https://leetcode.com/discuss/100820/recursive-recursive-solution-summary-with-detailed-comments
**/


/** C++ recursive solution **/


class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        /** the left most node, when backtrack we need to set the parent node left & right point to null **/
        if(!root || !root->left) return root;
        /** record the current left & right node before DFS **/
        TreeNode* cur_left = root->left;
        TreeNode* cur_right = root->right;
        /** DFS call to build the right sub tree **/
        TreeNode* new_root = upsideDownBinaryTree(root->left);
        cur_left->right = root;
        cur_left->left = cur_right;
        /** now the root node become the child node, so we need to clear the left & right sub node to avoid cycles**/
        root->left = nullptr;
        root->right = nullptr;
        return new_root;
    }
};


/** C++ non-recursive solution **/


class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        /** cur   : record the current root node 
         * parent : record the parent node of the current node
         * right  : record the right child node of the parent node 
         * next   : record the next level left child node **/
        TreeNode* cur = root;
        TreeNode* parent = NULL;
        TreeNode* right = NULL;
        TreeNode* next = NULL;
        while(cur != NULL) {
            next = cur->left;
            /** set the cur->left point to right and cur->right point to parent **/
            cur->left = right;
            right = cur->right;
            cur->right = parent;
            parent = cur;
            /** move left down to the next node **/
            cur = next;
        }
        return parent;
    }
};