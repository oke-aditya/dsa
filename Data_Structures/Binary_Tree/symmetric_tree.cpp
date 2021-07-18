// https://leetcode.com/problems/symmetric-tree/

// Given the root of a binary tree, 
// check whether it is a mirror of itself (i.e., symmetric around its center).

// Input: root = [1,2,2,3,4,4,3]
// Output: true

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *left, *right;
};


// Recursive Solution

// Two trees are a mirror reflection of each other if:

//     Their two roots have the same value.
//     The right subtree of each tree is a mirror reflection of the left subtree of the other tree.

// Push an element in stack
// Time complexity : O(n)
// Space complexity : O(n)

bool isMirror(TreeNode *t1, TreeNode *t2)
{
    if(t1 == NULL && t2 == NULL)
    {
        return true;
    }
    
    if(t1 == NULL || t2 == NULL)
    {
        return false;
    }
    
    return ((t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right));    
}

bool isSymmetric(TreeNode* root) 
{
    return isMirror(root, root);
}

// Iterative BFS Style solution

// . Initially, the queue contains root and root. 
// Then the algorithm works similarly to BFS, with some key differences. 
// Each time, two nodes are extracted and their values compared. 
// Then, the right and left children of the two nodes 
// are inserted in the queue in opposite order. 
// The algorithm is done when either the queue is empty, or we detect that the tree is not symmetric 

bool isSymmetric(TreeNode* root) 
{
    queue<TreeNode *> q;
    
    q.push(root);
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode *node1 = q.front();
        q.pop();
        TreeNode *node2 = q.front();
        q.pop();
        
        if(node1 == NULL && node2 == NULL)
        {
            continue;
        }
        
        if(node1 == NULL || node2 == NULL)
        {
            return false;
        }
        
        if(node1->val != node2->val)
        {
            return false;
        }
        
        q.push(node1->left);
        q.push(node2->right);
        q.push(node1->right);
        q.push(node2->left);
    }   
    return true;
}
