// https://leetcode.com/problems/sum-of-left-leaves/

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *left, *right;
};


int sumOfLeftLeaves(TreeNode* root) 
{

    if(root == NULL)
        return 0;

    queue<TreeNode *> q;
    q.push(root);

    int sum = 0;
    while(!q.empty())
    {
        int n = q.size();

        for(int i=0; i<n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            
            // this is left node.
            if(node->left != NULL)
            {

                q.push(node->left);

                TreeNode *node2 = node->left;

                // this is a leaf node.
                if(node2->left == NULL && node2->right == NULL)
                {
                    sum += node2->val;
                }

            }
            if(node->right != NULL)
            {
                q.push(node->right);
            }
        }
    }

    return sum;


}