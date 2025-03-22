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

// The idea is quite simple.
// Max value of Height(leftSubtree) +
// Height(rightSubtree) (at any node) is the diameter.
// Keep track of maximum diameter duing traversal and
// find the height of the tree.

int diameter_tree(Node *node) {
  int d = 0;
  auto _ = dmtree(node, d);
  return d;
}

int dmtree(Node *node, int &d) {
  if (node == NULL) {
    return 0;
  }

  int ld = dmtree(node->left, d);
  int rd = dmtree(node->right, d);

  d = max(d, ld + rd);
  return max(ld, rd) + 1;
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
