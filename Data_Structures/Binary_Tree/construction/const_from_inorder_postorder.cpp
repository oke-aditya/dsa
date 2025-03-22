// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Given two integer arrays inorder and postorder where inorder is the inorder
// traversal of a binary tree and postorder
// is the postorder traversal of the same tree, construct and return the binary
// tree.

// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]

// Solution : -
// In this case we can construct a distinct tree.
// So there is only one solution for given inputs.
//
//

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *left, *right;

  Node(int data) { this->data = data; }
};

Node *solve(vector<int> &inorder, int inOrderStart, int inOrderEnd,
            vector<int> &postorder, int postOrderStart, int postOrderEnd,
            map<int, int> mp) {
  if (postOrderStart > postOrderEnd || inOrderStart > inOrderEnd) return NULL;

  // Last node of postOrder traversal is the root.
  Node *root = new Node(postorder[postOrderEnd]);

  int inRoot = mp[postorder[postOrderEnd]];
  int numLeft = inRoot - inOrderStart;

  root->left = solve(inorder, inOrderStart, inRoot - 1, postorder,
                     postOrderStart, postOrderStart + numLeft - 1, mp);

  root->right = solve(inorder, inRoot + 1, inOrderEnd, postorder,
                      postOrderStart + numLeft, postOrderEnd - 1, mp);

  return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
  if (inorder.size() != postorder.size()) return NULL;

  map<int, int> mp;

  for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

  return solve(inorder, 0, inorder.size() - 1, postorder, 0,
               postorder.size() - 1, mp);
}
