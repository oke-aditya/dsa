// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

// Left boundary nodes: defined as the path
// from the root to the left-most node ie- the leaf node you could reach when you always
// travel preferring the left subtree over the right subtree. 
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// Reverse right boundary nodes: defined as the path from the
// right-most node to the root. The right-most node is the leaf
// node you could reach when you always travel preferring the right subtree
// over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

// Note: If the root doesn't have a left subtree or right
// subtree, then the root itself is the left or right boundary. 

// Input:
//         1
//       /   \
//      2     3    
   
// Output: 1 2 3

// Input:
//           20
//         /   \
//        8     22
//      /   \    \
//     4    12    25
//         /  \ 
//        10   14 

// Output: 20 8 4 10 14 25 22

// Solution

// We break the problem in 3 parts:
// 1. Print the left boundary in top-down manner.
// 2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
// …..2.1 Print all leaf nodes of left sub-tree from left to right.
// …..2.2 Print all leaf nodes of right subtree from left to right.
// 3. Print the right boundary in bottom-up manner.


#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
        int data;
        Node *left, *right;
};

// Print the leaf nodes of tree.
void print_leaves(Node *root, vector<int> &res)
{
    if(root == NULL)
    {
        return;
    }

    // Recursively call for left
    print_leaves(root->left, res);

    // Has neither left or right.
    if(!(root->left) && !(root->right))
    {
        res.push_back(root->data);
    }

    // Go for right.
    print_leaves(root->right, res);
}

// Print all right boundary nodes except leaf node.
void print_boundary_left(Node *root, vector<int> &res)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left)
    {
        // to ensure bottom up order print the node and then call left.
        res.push_back(root->data);
        print_boundary_left(root->left, res);
    }

    else if(root->left)
    {
        res.push_back(root->data);
        print_boundary_left(root->right, res);
    }

    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output

    return;
}


// Print all right boundary nodes except leaf node.
void print_boundary_right(Node *root, vector<int> &res)
{

    if(root == NULL)
    {
        return;
    }

    if(root->right)
    {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        print_boundary_right(root->right, res);
        res.push_back(root->data);
    }

    else if(root->left)
    {
        print_boundary_right(root->left, res);
        res.push_back(root->data);
    }

    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output

    return;
}

vector <int> print_boundary(Node *root)
{
    vector<int> res;

    if(root == NULL)
    {
        return;
    }

    res.push_back(root->data);

    print_boundary_left(root->left, res);
    print_leaves(root->left, res);
    print_leaves(root->right, res);
    
    print_boundary_right(root->right, res);

    return res;

}




int main(int argc, char const *argv[])
{
    
    return 0;
}


