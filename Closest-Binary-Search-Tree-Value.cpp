//
// Created by pianocoder on 16/5/8.
//
/**
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
        Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
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
    int closestValue(TreeNode* root, double target) {

    }
};