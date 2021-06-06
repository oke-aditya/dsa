// The following is the definition of Binary Search Tree(BST) according to Wikipedia
// Binary Search Tree is a node-based binary tree data structure which has the following properties:  

//     The left subtree of a node contains only nodes with keys lesser than the node’s key.
//     The right subtree of a node contains only nodes with keys greater than the node’s key.
//     The left and right subtree each must also be a binary search tree. 
//     There must be no duplicate nodes.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        Node *left, *right;
        int data;
};

// Use the BST property to search.
Node *search(Node *root, int key)
{
    if(root == NULL || root->data == key)
    {
        return root;
    }

    if(root->data < key)
    {
        return search(root->right, key);
    }

    // Otherwise it's less
    return search(root->left, key);
}

// To insert, find the position and create a new node
Node *insert(Node *root, int key)
{
    if(root == NULL)
    {
        Node *newnode = new Node();
        newnode->data = key;
        return newnode;
        // If you have a constructor.
        // return new Node(key);
    }

    // This logic avoid duplicate insertion.
    if(key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else if(key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        return root;
    }
    return root;
}

