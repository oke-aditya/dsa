// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

//     The left subtree of a node contains only nodes with keys less than the node's key.
//     The right subtree of a node contains only nodes with keys greater than the node's key.
//     Both the left and right subtrees must also be binary search trees.


#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        Node *left, *right;
        int data;
};


bool is_bst(Node *root)
{
    if(root == NULL)
    {
        return true;
    }

    stack<Node*> stk;
    Node* pre = NULL;

    while (root != NULL || !stk.empty())
    {
        while (root != NULL)
        {
            stk.push(root);
            root = root->left;
        }
        
        root = stk.top();
        stk.pop();

        if(pre != NULL && root->data <= pre->data)
        {
            return false;
        }
        pre = root;
        root = root->right;
    }
    return true;
}

