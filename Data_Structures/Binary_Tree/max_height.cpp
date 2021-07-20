// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the
// longest path from the root node down to the farthest leaf node.

// Solution: -

// Simple Recursive Approach
// Max depth can occur either left or right
// maximum depth is max of either + 1.
// 


#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};

int max_depth(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int l_depth = max_depth(root->left);
        int r_depth = max_depth(root->right);
        return max(l_depth, r_depth) + 1;
    }
}

