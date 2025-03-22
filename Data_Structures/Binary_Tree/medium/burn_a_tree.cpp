// Given a binary tree and a node called target.
// Find the minimum time required to burn the complete binary tree
// if the target is set on fire.
// It is known that in 1 second all nodes connected to a given node get burned.
// That is its left child, right child, and parent.

// Tree :   1
//         / \ 
//         2   3
//         /   / \
//         4   5   6
// B = 4

// Explanation 1:

// After 1 sec: Node 4 and 2 will be burnt.
// After 2 sec: Node 4, 2, 1 will be burnt.
// After 3 sec: Node 4, 2, 1, 3 will be burnt.
// After 4 sec: Node 4, 2, 1, 3, 5, 6(whole tree) will be burnt.

// Solution
// We first map the parents of given target node.
// After we map the parents of target, we do a BFS
// In BFS we mark the visited nodes so that we don't visit them again.
// This is similar to node at level k. Except we will continue BFS.

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *left, *right;
};

// Start denotes the value of the node which is being burnt.
// We need to find the location of start while doing parent mapping too.
Node *mapParents(Node *root, map<Node *, Node *> &mp, int start) {
  queue<Node *> q;
  q.push(root);

  Node *res;

  while (!q.empty()) {
    Node *node = q.front();

    // If we find the start node, we need it.
    // We need the location where burning starts.
    if (node->data == start) {
      res = node;
    }
    q.pop();

    if (node->left) {
      mp[node->left] = node;
      q.push(node->left);
    }

    if (node->right) {
      mp[node->right] = node;
      q.push(node->right);
    }
  }

  // Return the location where burning is gonna occur.
  return res;
}

int findMaxDistance(map<Node *, Node *> &mp, Node *target) {
  queue<Node *> q;
  q.push(target);

  map<Node *, bool> vis;
  vis[target] = true;
  int maxi = 0;

  while (!q.empty()) {
    int sz = q.size();
    int fl = 0;
    for (int i = 0; i < sz; i++) {
      Node *node = q.front();
      q.pop();

      if (node->left && !vis[node->left]) {
        fl = 1;
        vis[node->left] = true;
        q.push(node->left);
      }

      if (node->right && !vis[node->right]) {
        fl = 1;
        vis[node->right] = true;
        q.push(node->right);
      }

      if (mp[node] && !vis[mp[node]]) {
        fl = 1;
        vis[mp[node]] = true;
        q.push(mp[node]);
      }
    }

    if (fl) maxi += 1;
  }

  return maxi;
}

int timeToBurnTree(Node *root, int start) {
  map<Node *, Node *> mp;
  Node *target = mapParents(root, mp, start);

  int maxi = findMaxDistance(mp, target);
  return maxi;
}
