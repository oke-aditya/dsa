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

  void dfs(TreeNode *root, int &sum, bool is_left) {
      if(root == nullptr)
          return ;

      // since we moved left, this is a left node and leaf node
      if(is_left && root->left == nullptr && root->right == nullptr)
          sum += root->val;
      dfs(root->left, sum, true);
      dfs(root->right, sum, false);
  }


  int sumOfLeftLeaves2(TreeNode* root) {
      // don't do a BFS
      // it's hard to identify left node

      int sum = 0;
      bool is_left = false;
      dfs(root, sum, is_left);
      return sum;

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