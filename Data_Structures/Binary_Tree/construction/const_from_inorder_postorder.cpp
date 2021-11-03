// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Given two integer arrays inorder and postorder where inorder is the inorder 
// traversal of a binary tree and postorder 
// is the postorder traversal of the same tree, construct and return the binary tree.

// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]

// Solution : -
// In this case we can construct a distinct tree.
// So there is only one solution for given inputs.
// 
// 

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




