// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

// Given the root of a binary tree, the level of its root is 1, the level of its
// children is 2, and so on. Return the smallest level x such that the sum of
// all the values of nodes at level x is maximal.

// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation:
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.

#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode *root) {
  priority_queue<pair<long long, int>> maxh;
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
    if (!maxh.empty()) {
      if (level_sum > maxh.top().first) {
        maxh.push(make_pair(level_sum, level));
      }
    } else {
      maxh.push(make_pair(level_sum, level));
    }
  }
  return maxh.top().second;
}
