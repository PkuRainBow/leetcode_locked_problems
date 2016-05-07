//
// Created by pianocoder on 16/5/8.
//

/**

 Closest Binary Search Tree Value II

 Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?


Hint:
1 Consider implement these two helper functions:
     getPredecessor(N), which returns the next smaller node to N.
     getSuccessor(N), which returns the next larger node to N.
2 Try to assume that each node has a parent pointer, it makes the problem much easier.
3 Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
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
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {

    }
};
