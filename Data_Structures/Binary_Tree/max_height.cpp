// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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


int max_depth2(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    queue<Node *> q;

    q.push(root);

    int count = 0;

    while(!q.empty())
    {
        int n = q.size();
        count += 1;
        for(int i=0; i<n; i++)
        {
            Node *node = q.front();
            q.pop();

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

    return count;

}