// Given a Binary Tree with all unique values and two nodes value n1 and n2. 
// The task is to find the lowest common ancestor of the given two nodes.
// We may assume that either both n1 and n2 are present in the tree or none of them is present. 

// n1 = 3 , n2 = 4
//          5
//         /
//        2
//      /  \
//     3    4
// Output: 2
// Explanation: 
// LCA of 3 and 4 is 2. 


#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};

Node* lca(Node* root, int n1, int n2)
{
    if(root == NULL)
    {
        // Sometimes some compilers need root as answer
        return NULL;
    }

    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if(root->data == n1 || root->data == n2)
    {
        return root;
    }

    // Find left lca and right lca
    Node *left_lca = lca(root->left, n1, n2);
    Node *right_lca = lca(root->right, n1, n2);

    // Check if either is null
    if(left_lca && right_lca)
    {
        // Sometimes some compilers need root as answer
        return NULL;
    }

    // Either is NULL, check and return;
    if(left_lca != NULL)
    {
        return left_lca;
    }
    else
    {
        return right_lca;
    }
}


// If pointers are given we can slightly modify
Node* lca_p(Node* root, Node* n1, Node* n2)
{
    if(root == NULL)
    {
        // Sometimes some problems need root as answer
        return NULL;
    }

    if(root == n1 || root == n2)
    {
        return root;
    }

    // Find left lca and right lca
    Node *left_lca = lca_p(root->left, n1, n2);
    Node *right_lca = lca_p(root->right, n1, n2);

    // If either is NULL
    if(left_lca && right_lca)
    {
        // Sometimes some problems need root as answer
        return NULL;
    }

    // Either is NULL, check and return;
    if(left_lca != NULL)
    {
        return left_lca;
    }
    else
    {
        return right_lca;
    }
}


int main(int argc, char const *argv[])
{
    
    return 0;
}


