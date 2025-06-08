// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/
// You are given the root of a binary tree and a positive integer k.

// The level sum in the tree is the sum of the values of the nodes that are on
// the same level.

// Return the kth largest level sum in the tree (not necessarily distinct). If
// there are fewer than k levels in the tree, return -1.

// Note that two nodes are on the same level if they have the same distance from
// the root.

// Input: root = [5,8,9,2,1,3,7,4,6], k = 2
// Output: 13
// Explanation: The level sums are the following:
// - Level 1: 5.
// - Level 2: 8 + 9 = 17.
// - Level 3: 2 + 1 + 3 + 7 = 13.
// - Level 4: 4 + 6 = 10.
// The 2nd largest level sum is 13.

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

long long kthLargestLevelSum(TreeNode *root, int k) {
  priority_queue<long long, vector<long long>, greater<long long>> minh;
  queue<TreeNode *> q;
  int level = 0;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    long long level_sum = 0;
    level += 1;
    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front();
      q.pop();

      level_sum += node->val;

      if (node->left != NULL) {
        q.push(node->left);
      }

      if (node->right != NULL) {
        q.push(node->right);
      }
    }

    minh.push(level_sum);
    if (minh.size() > k) {
      minh.pop();
    }
  }

  if (minh.size() < k) {
    return -1;
  } else {
    return minh.top();
  }
}
