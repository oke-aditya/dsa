// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

// Right view of following tree is 1 3 7 8.

//           1
//        /     \
//      2        3
//    /   \      /    \
//   4     5   6    7
//     \
//      8


// Solution: -

// Very similar to left view we will again use BFS.

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *left, *right;

};


vector<int> rightSideView(TreeNode* root) 
{
    vector<int> res;

    if(root == NULL)
    {
        return res;
    }

    queue<TreeNode *> q;
    q.push(root);

    // res.push_back(root->val);

    while(!q.empty())
    {
        int n = q.size();
        for(int i=0; i<n; i++)
        {

            TreeNode *node = q.front();
            q.pop();

            if(i == n-1)
            {
                res.push_back(node->val);
            }

            if(node->left != NULL)
            {
                q.push(node->left);
            }

            if(node->right != NULL)
            {
                q.push(node->right);
            }
        }
    }
}
