// implement basic binary tree
// support operations such as insert, delete, search, traverse
// use latest C++ syntax

#include <iostream>

using namespace std;

enum direction { LEFT, RIGHT };

class Node {
 public:
  // deafult constructor
  Node(int data) : val(data), left(nullptr), right(nullptr) {}

  // simple inorder traversal
  void printTree(Node *root) {
    // safe check
    if (root == nullptr) {
      return;
    }

    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
  }

  // insert an item to this node direction
  void insert(Node *node, int data, direction dir) {
    if (node == nullptr) {
      return;
    }
    Node *new_node = new Node(data);
    if (dir == LEFT) {
      node->left = new_node;
    }

    else if (dir == RIGHT) {
      node->right = new_node;
    }
    return;
  }

  // delete this particular node
  // but make sure to keep the tree connected
  void delete_node(Node *node) {
    if (node == nullptr) {
      return;
    }

    // if it's a leaf
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
    }

    // if either exists
    else if (node->left != nullptr && node->right == nullptr) {
      // you can't assign this.
      // pointers don't move. Missing out on parent ->node connections.
      // node = node->left; // WRONG
      // Use a temp pointer and do swaps
      Node *temp = node->left;
      node->val = temp->val;
      node->left = temp->left;
      node->right = temp->right;
      delete temp;
    }

    // if either exists
    else if (node->right != nullptr && node->left != nullptr) {
      // Same reason this would be wrong
      // WRONG node = node->right;
      Node *temp = node->right;
      node->val = temp->val;
      node->left = temp->left;
      node->right = temp->right;
      delete temp;
    }

    // both exists, so we can choose either
    // in case of other trees we would have to take efforts and find in order
    // successors
    else {
      // take right just for simplicity
      Node *temp = node->right;

      // find the last left node alive
      while (temp->left != nullptr) {
        temp = temp->left;
      }
      node->val = temp->val;
      delete_node(temp);
    }
  }

 public:
  int val;
  Node *left, *right;
};

// driver
int main() {
  Node *root = new Node(10);

  // try to draw the tree! It is important to viz this

  root->insert(root, 5, LEFT);
  root->insert(root, 20, RIGHT);
  root->insert(root->right, 17, LEFT);
  root->insert(root->right->left, 10, LEFT);
  root->insert(root->right->left->left, 19, RIGHT);

  cout << "Initial tree: ";
  root->printTree(root);
  cout << endl;

  root->delete_node(root->right->left);
  root->printTree(root);
}
