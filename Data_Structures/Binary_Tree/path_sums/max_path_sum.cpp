// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes
// from some starting node to any node in the tree along
// the parent-child connections.
// The path must contain at least one node and does not need to go through the
// root.

// Example 1:

// Input: [1,2,3]

//        1
//       / \
//      2   3

// Output: 6
// Example 2:

// Input: [-10,9,20,null,null,15,7]

//    -10
//    / '\'
//   9  20
//     /  '\'
//    15   7

// Output: 42

#include <bits/stdc++.h>
using namespace std;

int res = INT_MIN;

class Node {
 public:
  int data;
  Node *left, *right;
};

Node *newnode(int new_data) {
  Node *new_node = new Node;
  new_node->data = new_data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

int max_path(Node *node) {
  if (node == NULL) {
    return 0;
  }

  // Solve the left part
  int l = max_path(node->left);
  int r = max_path(node->right);

  // When max_path_sum passes through itself.
  // Either value is maximum of two and itself.
  int temp = max(max(l, r) + node->data, node->data);

  // When max_path_sum passes through root, it passes its value.
  int ans = max(temp, l + r + node->data);

  res = max(res, ans);

  return res;
}

int main(int argc, char const *argv[]) {
  Node *root = newnode(-10);
  root->left = newnode(9);
  root->right = newnode(20);
  root->right->left = newnode(15);
  root->right->right = newnode(7);

  cout << "Longest pat sum = " << max_path(root) << endl;

  return 0;
}
