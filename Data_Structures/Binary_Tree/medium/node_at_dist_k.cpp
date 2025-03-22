// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Given the root of a binary tree, the value of a target node target,
// and an integer k, return an array of the values
// of all nodes that have a distance k from the target node.

// You can return the answer in any order.

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance
//                2 from the target node (with value 5) have values 7, 4, and 1.

// Solution
// Our first job should be to mark the parent nodes of the target
// We cannot traverse from the target node, as we don't know the left / right or
// path. We should first do BFS to mark parents for the target node, with help
// of root node.

// Once paretns are marked. We can do BFS again and find notes at the given
// level. But we need to visit only the nodes that are needed. We need to mark
// the visited nodes and move ahead. This is difference in BFS, to distinguish
// nodes that are already visited. This happens since we are not at the root of
// the tree.

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *left, *right;
};

// Simple BFS to mark targets
void markParents(Node *root, unordered_map<Node *, Node *> &parent_track) {
  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if (temp->left) {
      parent_track[temp->left] = temp;
      q.push(temp->left);
    }

    if (temp->right) {
      parent_track[temp->right] = temp;
      q.push(temp->right);
    }
  }
}

vector<int> distanceK(Node *root, Node *target, int k) {
  unordered_map<Node *, Node *> parent_track;

  // Get the child->parent relationship in the "parents" map.
  markParents(root, parent_track);

  // Hash to store the nodes which are already visited so we do not fall in an
  // infinite loop
  unordered_map<Node *, bool> visited;

  queue<Node *> q;
  q.push(target);

  visited[target] = true;

  int current_level = 0;

  while (!q.empty()) {
    int sz = q.size();

    // If we are already at level 'K', then we break since queue will have our
    // distance K nodes otherwise increase the level
    if (current_level == k) break;

    current_level += 1;

    // For the size number of elements in the queue, keep trying to visit them
    // and push in the queue This is needed because this will tell us the number
    // of nodes which are at the same level. This is really important to
    // understand that when the control comes here the number of elements in the
    // queue are all at the same level. While the loop runs, it may increase but
    // the 'size' variable is still the same and it will stop. The new nodes
    // which are added are all at the same level. NOTE:  Putting NULL marker
    // after the level ends will not work here.
    for (int i = 0; i < sz; i++) {
      Node *node = q.front();
      visited[node] = true;
      q.pop();

      if (node->left && !visited[node->left]) {
        q.push(node->left);
        visited[node->left] = true;
      }

      if (node->right && !visited[node->right]) {
        q.push(node->right);
        visited[node->right] = false;
      }

      // If the node has a parent.
      // And we haven't visited the parent.
      if (parent_track[node] && !visited[parent_track[node]]) {
        q.push(parent_track[node]);
        visited[parent_track[node]] = true;
      }
    }
  }

  vector<int> res;

  // Now the q contains all the results.
  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();
    res.push_back(curr->data);
  }

  return res;
}
