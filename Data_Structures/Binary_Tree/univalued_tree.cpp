// https://leetcode.com/problems/univalued-binary-tree/

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *left, *right;
};

bool isUnivalTree(TreeNode* root) {
    
    int root_val = root->val;
    
    // Now do a simple bfs / level order
    
    queue <TreeNode*> q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        
        if(node->val != root_val)
        {
            return false;
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
    
    return true;
    
    
}

