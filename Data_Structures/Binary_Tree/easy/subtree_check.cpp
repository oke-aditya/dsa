// https://leetcode.com/problems/subtree-of-another-tree/
// Given two binary trees with head reference as T and S having at most N nodes.
// The task is to check if S is present as subtree in T.
// A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its
// descendants in T1.

// Example 1:

// Input:
// T:      1          S:   3
//       /   \            /
//      2     3          4
//    /  \    /
//   N    N  4
// Output: 1
// Explanation: S is present in T

// Naive approach: -

// Traverse the tree T in preorder fashion.
// For every visited node in the traversal, see if the subtree rooted with this
// node is identical to S.

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *left, *right;
};

// Check if two nodes are identical.

bool are_identical(Node *root1, Node *root2) {
  // Base cases
  if (root1 == NULL && root2 == NULL) {
    return true;
  }

  if (root1 == NULL || root2 == NULL) {
    return false;
  }

  // Data of both roots is same, and left and right are same

  if (root1->data == root2->data) {
    return (are_identical(root1->left, root2->left) &&
            are_identical(root1->right, root2->right));
  } else {
    return false;
  }
}

// Now check if any subtree is identical.

bool is_subtree(Node *tree1, Node *tree2) {
  if (tree1 == NULL) {
    return false;
  }

  // Check if both tree are identical
  if (are_identical(tree1, tree2)) {
    return true;
  }

  // Now check if evert sub tree is identical
  // We need to check if either subtree of tree1 matches.
  return is_subtree(tree1->left, tree2) || is_subtree(tree1->right, tree2);
}

int main(int argc, char const *argv[]) { return 0; }
