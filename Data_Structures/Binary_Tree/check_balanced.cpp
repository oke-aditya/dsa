// Given a binary tree, find if it is height balanced or not. 
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

// A height balanced tree
//         1
//      /     \
//    10      39
//   /
// 5

// Input:
//        10
//      /   \
//     20   30 
//   /   \
//  40   60
// Output: 1
// Explanation: The max difference in height
// of left subtree and right subtree is 1.
// Hence balanced. 


#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
        int data;
        Node *left;
        Node *right;
};

int height(Node *node)
{
    // Caculate height of tree.
    if(node == NULL)
    {
        return 0;
    }

    return 1 + max(height(node->left), height(node->right));
}


// Function to check whether a binary tree is balanced or not.
// This is O(N2) as it recomputes height everytime.
bool isBalanced(Node *root)
{
    int lh, rh;
    if(root == NULL)
    {
        return true;
    }

    // Get the left height
    lh = height(root->left);
    rh = height(root->right);

    if(isBalanced(root->left) && isBalanced(root->right) && abs(lh-rh) <= 1)
    {
        return true;
    }

    return false;
}
