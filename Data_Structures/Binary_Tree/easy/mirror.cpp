// https://leetcode.com/problems/invert-binary-tree/
// Also called invert a binary tree.
// Mirror of a Tree: Mirror of a Binary Tree T is 
// another Binary Tree M(T) with left and right 
// children of all non-leaf nodes interchanged.
// 
// (1)  Call Mirror for left-subtree    i.e., Mirror(left-subtree)
// (2)  Call Mirror for right-subtree  i.e., Mirror(right-subtree)
// (3)  Swap left and right subtrees.
//           temp = left-subtree
//           left-subtree = right-subtree
//           right-subtree = temp

#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
        int data;
        Node *left, *right;
};


Node* mirror(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        // Call mirror on left sub tree
        mirror(root->left);
        
        // Call mirror on right.
        mirror(root->right);

        // Swap
        swap(root->left, root->right);
    }
    return root;
}

Node* mirror2(Node *root)
{
    if(root == NULL)
    {
        return root;
    }
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty())
    {
        
        Node *node = q.front();
        q.pop();
        swap(node->left, node->right);
        
        if(node->left != NULL)
        {
            q.push(node->left);
        }
        
        if(node->right != NULL)
        {
            q.push(node->right);
        }
    }
    return root;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}

