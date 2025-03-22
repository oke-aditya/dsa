// https://leetcode.com/problems/sum-of-left-leaves/
// Given the root of a binary tree, return the sum of all left leaves.

// A leaf is a node with no children. A left leaf is a leaf that is the left
// child of another node.

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
};

int dfs(TreeNode *root, bool is_left) {
  if (root == NULL) {
    return 0;
  }

  if (root->left == NULL && root->right == NULL) {
    if (is_left) {
      return root->val;
    } else {
      return 0;
    }
  }

  int left_sum = dfs(root->left, true);
  int right_sum = dfs(root->right, false);
  return left_sum + right_sum;
}

int sumOfLeftLeaves(TreeNode *root) {
  if (root == NULL) return 0;

  queue<TreeNode *> q;
  q.push(root);

  int sum = 0;
  while (!q.empty()) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front();
      q.pop();

      // this is left node.
      if (node->left != NULL) {
        q.push(node->left);

        TreeNode *node2 = node->left;

        // this is a leaf node.
        if (node2->left == NULL && node2->right == NULL) {
          sum += node2->val;
        }
      }
      if (node->right != NULL) {
        q.push(node->right);
      }
    }
  }

  return sum;
}