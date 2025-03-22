// Serialize and Deserialize a Binary Tree

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Serialization is the process of converting a
// data structure or object into a sequence of bits so that it can be
// stored in a file or memory buffer, or transmitted across a network
// connection link to be reconstructed later in the same or another computer
// environment.

// Design an algorithm to serialize and deserialize a binary /
// tree. There is no restriction on how your serialization/deserialization
// algorithm should work. You just need to ensure that a binary tree can be
// serialized to a string and this string can be deserialized to the original
// tree structure.

// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *left, *right;

  Node(int data) { this->data = data; }
};

string serialize(Node *root) {
  // Simple BFS to serialize to string.
  if (root == NULL) return "";

  string s = "";

  queue<Node *> q;

  q.push(root);

  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();

    if (curr == NULL)
      s += "#,";

    else
      s = s + to_string(curr->data) + ',';

    if (curr != NULL) {
      q.push(curr->left);
      q.push(curr->right);
    }
  }
  return s;
}

Node *deserialize(string data) {
  if (data.length() == 0) return NULL;

  stringstream s(data);

  string str;
  getline(s, str, ',');

  Node *root = new Node(stoi(str));
  queue<Node *> q;

  q.push(root);

  // BFS Again

  while (!q.empty()) {
    Node *node = q.front();
    q.pop();

    getline(s, str, ',');

    if (str == "#") {
      node->left = NULL;
    }

    else {
      Node *leftNode = new Node(stoi(str));
      node->left = leftNode;
      q.push(leftNode);
    }

    getline(s, str, ',');

    if (str == "#") {
      node->right = NULL;
    }

    else {
      Node *rightNode = new Node(stoi(str));
      node->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}
