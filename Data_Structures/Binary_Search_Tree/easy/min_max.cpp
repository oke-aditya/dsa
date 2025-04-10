// Finding minimum and maximum value in BST.

// We can exploit the structural property of BST.

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  Node *left, *right;
  int data;
};

int min_value(Node *node) {
  Node *curr = node;

  // smallest is always towards left.
  while (curr->left != NULL) {
    curr = curr->left;
  }

  // Now current has no left.

  return curr->data;
}

int max_value(Node *node) {
  Node *curr = node;

  // Greatest value is always towards right

  while (curr->right != NULL) {
    curr = curr->right;
  }

  return curr->data;
}
