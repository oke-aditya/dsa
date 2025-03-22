// Diameter of Tree

// Given a binary tree, you need to compute the length of the diameter of the
// tree. The diameter of a binary tree is the length of the longest path between
// any two nodes in a tree. This path may or may not pass through the root.

// Example:
// Given a binary tree
//           1
//          / '\'
//         2   3
//        / \     
//       4   5

// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

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

int diameter_tree(Node *node) {
  if (node == NULL) {
    return 0;
  }
  int l = diameter_tree(node->left);
  int r = diameter_tree(node->right);

  // Case where we pass through root for diamater.
  res = max(res, (1 + l + r));

  // Pass throught own for diameter.
  res = 1 + max(l, r);

  return res;
}

int main(int argc, char const *argv[]) {
  Node *root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  root->left->left = newnode(4);
  root->left->right = newnode(5);

  cout << "diameter of tree: " << diameter_tree(root) << endl;

  return 0;
}
