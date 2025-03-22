// A Binary Tree node contains following parts.

//     Data
//     Pointer to left child
//     Pointer to right child

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *left, *right;
};

int main(int argc, char const *argv[]) {
  Node *root = new Node();
  root->data = 1;

  root->left->data = 2;

  root->right->data = 3;

  root->left = new Node();
  root->left->data = 4;

  return 0;
}
