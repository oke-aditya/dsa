// 1. If tree is empty then return 0
// 2. Else
//     (a) Get the max depth of left subtree recursively  i.e.,
//         call maxDepth( tree->left-subtree)
//     (a) Get the max depth of right subtree recursively  i.e.,
//         call maxDepth( tree->right-subtree)
//     (c) Get the max of max depths of left and right
//         subtrees and add 1 to it for the current node.
//         max_depth = max(max dept of left subtree,
//                             max depth of right subtree)
//                             + 1
//     (d) Return max_depth

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *left;
  Node *right;
};

Node *newNode(int data) {
  Node *new_node = new Node();
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->data = data;

  return new_node;
}

int height_rec(Node *root) {
  if (root == NULL) {
    return 0;
  } else {
    int l_depth = height_rec(root->left);
    int r_depth = height_rec(root->right);

    return max(l_depth, r_depth) + 1;
  }
}

int main(int argc, char const *argv[]) {
  Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  cout << "Height of tree " << height_rec(root) << endl;

  return 0;
}
