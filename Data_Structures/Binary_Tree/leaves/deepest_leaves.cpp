// https://leetcode.com/problems/deepest-leaves-sum/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
};

vector<int> bfs(TreeNode* root) {
  queue<TreeNode*> q;
  vector<int> res;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      TreeNode* node = q.front();
      q.pop();
      sum += node->val;

      if (node->left != NULL) {
        q.push(node->left);
      }

      if (node->right != NULL) {
        q.push(node->right);
      }
    }
    res.push_back(sum);
  }
  return res;
}

int deepestLeavesSum(TreeNode* root) {
  vector<int> res = bfs(root);
  return res[res.size() - 1];
}
