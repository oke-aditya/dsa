// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

#include<bits/stdc++.h>

using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *left, *right;
};


int min_diff = INT_MAX;
TreeNode *prev = NULL;

void dfs(TreeNode *root)
{
    if(root == NULL)
        return;

    dfs(root->left);

    if (prev != NULL)
    {
        min_diff = min(min_diff, abs(prev->val - root->val));
    }

    prev = root;

    dfs(root->right);

}


int getMinimumDifference(TreeNode* root) {
    dfs(root);      
    return min_diff;
}