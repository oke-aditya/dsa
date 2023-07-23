/*

// https://leetcode.com/problems/path-sum/
Given a tree and a sum, return true if there is a path from the root
down to a leaf, such that adding up all the values along the path
equals the given sum.
 
Strategy: subtract the node value from the sum when recurring down,
and check to see if the sum is 0 when you run out of tree.
*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *left, *right;
};


bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL)
    {
        return false;
    }


    bool ans = false;

    int remaining = targetSum - root->val;

    if(remaining == 0 && root->left == NULL & root->right == NULL)
    {
        return true;
    }

    if(root->left)
    {
        ans = ans || hasPathSum(root->left, remaining);
    }

    if(root->right)
    {
        ans = ans || hasPathSum(root->right, remaining);
    }

    return ans;
}

// Find the maximum path sum in tree from root.

int max_path_sum(TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }

    // if this is the leaf.
    if(root->left == NULL && root->right == NULL)
    {
        return root->val;
    }

    int left = max_path_sum(root->left);
    int right = max_path_sum(root->right);

    if(left > right)
    {
        return left + root->val;
    }

    else
    {
        return right + root->val;
    }

}

