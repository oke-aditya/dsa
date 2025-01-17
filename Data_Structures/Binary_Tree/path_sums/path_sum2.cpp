// https://leetcode.com/problems/path-sum-ii/description/

// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values 
// in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
// A root-to-leaf path is a path starting from the root and ending at any leaf node. 
// A leaf is a node with no children.

// Solution:

// The trick here is backtracking! We backtrack the paths.
// Use the same backtracking pattern


//  Definition for a binary tree node.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



void dfs(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> &sol)
{
    if(root == NULL)
    {
        return;
    }

    int rem  = targetSum - root->val;

    sol.push_back(root->val);
    // we have found a solution
    if(rem == 0 && root->left == NULL && root->right == NULL)
    {
        res.push_back(sol);
    }

    dfs(root->left, rem, res, sol);
    dfs(root->right, rem, res, sol);
    sol.pop_back();

}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
{
    vector<vector<int>> res;
    vector<int> sol;
    dfs(root, targetSum, res, sol);

    return res;
    
}
