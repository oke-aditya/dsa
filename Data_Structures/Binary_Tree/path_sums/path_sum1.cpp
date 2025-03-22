/*

// https://leetcode.com/problems/path-sum/
Given a tree and a sum, return true if there is a path from the root
down to a leaf, such that adding up all the values along the path
equals the given sum.

Strategy: subtract the node value from the sum when recurring down,
and check to see if the sum is 0 when you run out of tree.
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
};

bool dfs(TreeNode *root, int targetSum) {
  if (root == NULL) {
    return false;
  }

  int rem = targetSum - root->val;

  // we have found a solution
  if (rem == 0 && root->left == NULL && root->right == NULL) {
    return true;
  }
  return dfs(root->left, rem) || dfs(root->right, rem);
}

bool hasPathSum(TreeNode *root, int targetSum) {
  if (root == NULL) {
    return false;
  }
  return dfs(root, targetSum);
}