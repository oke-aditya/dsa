// Given a Binary Tree, print left view of it.
// Left view of a Binary Tree is set of nodes visible when tree is visited from
// left side. Input :
//                  1
//                /   \
//               2     3
//              / \     \
//             4   5     6
// Output : 1 2 4

// Input :
//         1
//       /   \
//     2       3
//       \   
//         4
//           \
//             5
//              \
//                6
// Output :1 2 4 5 6
//
//
// Solution: -

// If we observe carefully, we will see that our main task is to print the left
// most node of every level. So, we will do a level order traversal on the tree
// and print the leftmost node at every level. Below is the implementation of
// above approach:
//

#include <bits/stdc++.h>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left, *right;
};

class Solution {
 public:
  vector<int> leftSideView(TreeNode *root) {
    vector<int> res;

    if (root == nullptr) {
      return res;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int ln = q.size();
      while (ln--) {
        TreeNode *node = q.front();
        q.pop();

        if (ln == 1) {
          res.push_back(node->val);
        }

        if (node->left != NULL) {
          q.push(node->left);
        }

        if (node->right != NULL) {
          q.push(node->right);
        }
      }
    }
    return res;
  }
};