// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


// Given two integer arrays preorder and inorder where preorder 
// is the preorder traversal of a binary tree and inorder is the 
// inorder traversal of the same tree, construct and return the binary tree.

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]

// Solution: -
// The first element in preorder will be root of the tree.
// The next elements are left and right subtree.
// But how to determine where the left and left and right sub tree end ?
// If we find the index where this element occurs in the inorder, 
// we will get the position where left subtree ends. And that's where right subtree solves.
// we can call this recursively.


#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;

    Node(int data)
    {
        this->data = data;
    }

};

Node* solve (vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> inMap)
{
    if(preStart > preEnd || inStart > inEnd)
        return NULL;
    

    // The first element of preorder will give us the node.
    Node *root = new Node(preorder[preStart]);

    // InRoot is index where the Root exists.
    int inRoot = inMap[root->data];

    // Number of elements in left.
    int numLeft = inRoot - inStart;

    // Start to build tree from position preStart + 1. (next index)
    // We end the left subtree at Start + numleft. (As left are done)
    // The inorder array starts from inStart, ends where the root is.
    root->left = solve(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, inMap);

    // Right subtree starts being built from start + number in left + 1,
    // We end where preorder has to end.
    // Inorder starts from inRoot + 1 and ends at inEnd.
    root->right = solve(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;

}


Node* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    // Map to store inorder node value and location.
    map<int, int> inMap;      

    for(int i=0; i<inorder.size(); i++)
        inMap[inorder[i]] = i;
    
    Node *root = solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

    return root;
}

