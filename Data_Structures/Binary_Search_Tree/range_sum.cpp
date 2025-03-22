// https://leetcode.com/problems/range-sum-of-bst/description/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
};

int res = 0;

void inorder(TreeNode* root, int low, int high) {
  if (root == NULL) return;

  inorder(root->left, low, high);
  if (root->val > high)
    return;
  else if (root->val >= low)
    res += root->val;

  inorder(root->right, low, high);
}

int rangeSumBST(TreeNode* root, int low, int high) {
  inorder(root, low, high);
  return res;
}