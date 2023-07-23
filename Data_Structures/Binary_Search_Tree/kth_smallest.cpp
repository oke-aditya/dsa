// Given the root of a binary search tree, and an integer k,
// return the kth (1-indexed) smallest element in the tree.

// Input: root = [3,1,4,null,2], k = 1
// Output: 1

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        Node *left, *right;
        int data;
};


int kthSmallest(Node* root, int k)
{
    stack<Node *> stk;

    // stk.push(root);

    while(!stk.empty() || root != NULL)
    {
        while(root != NULL)
        {
            stk.push(root);
            root = root->left;
        }

        root = stk.top();
        stk.pop();

        k -= 1;
        if(k == 0)
            return root->data;

        root = root->right;
    }
    return -1;
}
