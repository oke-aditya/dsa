// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Just a small twist to level order traversal.
// We just need to reverse after even levels.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};

vector<vector<int>> zigzagLevelOrder(Node* root) {
    // just a modification of level order
    
    vector<vector<int>> res;
    
    if(root == NULL)
        return res;
    
    queue <Node *> q;
    
    q.push(root);
    int cnt = 0;
    
    while(!q.empty())
    {
        vector <int> temp;
        int len = q.size();
        
        for(int i=0; i<len; i++)
        {
            Node* node = q.front();
            q.pop();
            temp.push_back(node->data);

            if(node->left != NULL)
            {
                q.push(node->left);
            }

            if(node->right != NULL)
            {
                q.push(node->right);
            }
        }
        
        if((cnt % 2 == 1))
        {
            reverse(temp.begin(), temp.end());
        }
        res.push_back(temp);
        cnt += 1;
    }
    
    return res;
}
