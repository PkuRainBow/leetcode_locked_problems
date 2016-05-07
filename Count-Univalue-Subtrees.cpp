//
// Created by pianocoder on 16/5/7.
//

/**
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.

 https://leetcode.com/discuss/50420/java-11-lines-added
**/
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
    int count = 0;
    bool helper(TreeNode* root, int val) {
        if (root == nullptr)
            return true;
        /** Update: see that | does not short-circuit the right operand
            and thus the counting will be on **/
        if (!helper(root->left, root->val) | !helper(root->right, root->val))
            return false;
        count ++;
        return root->val == val;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        helper(root, 0);
        return count;
    }
};


/** Java Solution
 *
public class Solution {
    public int countUnivalSubtrees(TreeNode root) {
        int[] count = new int[1];
        helper(root, count);
        return count[0];
    }

    private boolean helper(TreeNode node, int[] count) {
        if (node == null) {
            return true;
        }
        boolean left = helper(node.left, count);
        boolean right = helper(node.right, count);
        if (left && right) {
            if (node.left != null && node.val != node.left.val) {
                return false;
            }
            if (node.right != null && node.val != node.right.val) {
                return false;
            }
            count[0]++;
            return true;
        }
        return false;
    }
}
 **/