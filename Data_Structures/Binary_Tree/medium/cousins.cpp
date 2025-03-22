// https://leetcode.com/problems/cousins-in-binary-tree/

// Given the root of a binary tree with unique values and the values of two
// different nodes of the tree x and y, return true if the nodes corresponding
// to the values x and y in the tree are cousins, or false otherwise.

// Two nodes of a binary tree are cousins if they have the same
// depth with different parents.

// Note that in a binary tree, the root node is at the depth 0,
// and children of each depth k node are at the depth k +

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
};

bool isCousins(TreeNode *root, int x, int y) {
  queue<TreeNode *> q;

  q.push(root);

  unordered_map<int, int> mp;

  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front();
      q.pop();

      if (node->left != NULL) {
        // mark in map, (child, parent)
        mp[node->left->val] = node->val;
        q.push(node->left);
      }

      if (node->right != NULL) {
        mp[node->right->val] = node->val;
        q.push(node->right);
      }
    }

    if (mp.find(x) != mp.end() && mp.find(y) != mp.end() && mp[x] != mp[y]) {
      return true;
    }
    mp.clear();
  }

  return false;
}
