// https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes
// along the shortest path from the root
// node down to the nearest leaf node.

// Note: A leaf is a node with no children.

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int data;
  Node *left, *right;
};

// Simple Recursive modification of Max height

int minDepth(Node *root) {
  if (root == NULL) return 0;

  int min_r = 1 + minDepth(root->right);
  int min_l = 1 + minDepth(root->left);

  // to handle a flat binary tree
  if (min(min_r, min_l) == 1)
    return max(min_r, min_l);
  else
    return min(min_r, min_l);
}

// BFS Solution

int minDepth(Node *root) {
  if (root == NULL) {
    return 0;
  }

  queue<Node *> q;
  q.push(root);
  int count = 0;

  while (!q.empty()) {
    int len = q.size();
    count += 1;
    for (int i = 0; i < len; i++) {
      Node *node = q.front();
      q.pop();

      if (node->left == NULL && node->right == NULL) {
        return count;
      }

      if (node->left != NULL) q.push(node->left);

      if (node->right != NULL) q.push(node->right);
    }
  }

  return count;
}
