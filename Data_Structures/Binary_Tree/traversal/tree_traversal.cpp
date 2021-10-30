// https://leetcode.com/problems/binary-tree-inorder-traversal/
// https://leetcode.com/problems/binary-tree-preorder-traversal/
// https://leetcode.com/problems/binary-tree-postorder-traversal/

// Three tree traversal algorithms are possible.

// Inorder Traversal): 

// Algorithm Inorder(tree)
//    1. Traverse the left subtree, i.e., call Inorder(left-subtree)
//    2. Visit the root.
//    3. Traverse the right subtree, i.e., call Inorder(right-subtree)


// Preorder Traversal: 

// Algorithm Preorder(tree)
//    1. Visit the root.
//    2. Traverse the left subtree, i.e., call Preorder(left-subtree)
//    3. Traverse the right subtree, i.e., call Preorder(right-subtree) 

// Postorder Traversal: 

// Algorithm Postorder(tree)
//    1. Traverse the left subtree, i.e., call Postorder(left-subtree)
//    2. Traverse the right subtree, i.e., call Postorder(right-subtree)
//    3. Visit the root.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};

void pre_order(Node *node)
{
    if(node == NULL)
    {
        return;
    }

    cout<<node->data<<" ";

    pre_order(node->left);

    pre_order(node->right);
}

void post_order(Node *node)
{
    if(node == NULL)
    {
        return;
    }

    post_order(node->left);

    post_order(node->right);

    cout<<node->data<<" ";

}

void in_order(Node *node)
{
    if(node == NULL)
    {
        return;
    }

    in_order(node->left);

    cout<<node->data<<" ";

    in_order(node->right);

}

int main(int argc, char const *argv[])
{
    Node *root = new Node();
    root->data = 1;
    root->left = new Node();
    root->right = new Node();
    
    root->left->data = 2;
    root->right->data = 3;

    root->left->left = new Node();
    root->left->right = new Node();
    
    root->left->left->data = 4;
    root->left->right->data = 5;

    cout<<"Pre order traversal "<<endl;
    pre_order(root);
    cout<<endl;

    cout<<"Post order traversal "<<endl;
    post_order(root);
    cout<<endl;

    cout<<"In order traversal "<<endl;
    in_order(root);
    cout<<endl;

    
    return 0;
}

