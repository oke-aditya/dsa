// https://leetcode.com/problems/invert-binary-tree/
// Also called invert a binary tree.
// Mirror of a Tree: Mirror of a Binary Tree T is
// another Binary Tree M(T) with left and right
// children of all non-leaf nodes interchanged.
//
// (1)  Call Mirror for left-subtree    i.e., Mirror(left-subtree)
// (2)  Call Mirror for right-subtree  i.e., Mirror(right-subtree)
// (3)  Swap left and right subtrees.
//           temp = left-subtree
//           left-subtree = right-subtree
//           right-subtree = temp

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
 public:
  int data;
  TreeNode *left, *right;
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        } 
        // Call mirror on left sub tree
        root->left = invertTree(root->left);

        // Call invertTree on right.
        root->right = invertTree(root->right);

        // Swap
        swap(root->left, root->right);
    
        return root;
    }
};

TreeNode *mirror2(TreeNode *root) {
  if (root == NULL) {
    return root;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    swap(node->left, node->right);

    if (node->left != NULL) {
      q.push(node->left);
    }

    if (node->right != NULL) {
      q.push(node->right);
    }
  }
  return root;
}

int main(int argc, char const *argv[]) { return 0; }
