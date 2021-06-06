// Delete a node in BST

// Given a Binary Search Tree and a node value X.
// Delete the node with the given value X from the BST.
// If no node with value x exists, then do not make any change. 
// Input:
//             1
//              \
//               2
//                 \
//                  8 
//                /    \
//               5      11
//             /  \    /  \
//            4    7  9   12
// X = 9
// Output: 1 2 4 5 7 8 11 12
// Explanation: In the given input tree after
// deleting 9 will be

#include<bits/stdc++.h>
using namespace std;

// Solution: -
// When we delete a node, three possibilities arise. 

// 1) Node to be deleted is the leaf: Simply remove from the tree. 

//               50                            50
//            /     \         delete(20)      /   \
//           30      70       --------->    30     70 
//          /  \    /  \                     \    /  \ 
//        20   40  60   80                   40  60   80


// 2) Node to be deleted has only one child: Copy the child to the node and delete the child 

//               50                            50
//            /     \         delete(30)      /   \
//           30      70       --------->    40     70 
//             \    /  \                          /  \ 
//             40  60   80                       60   80


// 3) Node to be deleted has two children: 
// Find inorder successor of the node. Copy contents of the inorder successor
// to the node and delete the inorder successor. Note that inorder predecessor can also be used. 
 

//               50                            60
//            /     \         delete(50)      /   \
//           40      70       --------->    40    70 
//                  /  \                            \ 
//                 60   80                           80


#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        Node *left, *right;
        int data;
};


Node *minValue(Node *node, int key)
{
    Node *current = node;

    // loop down to find the leftmost element
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}


// Delete a ndoe with the given key.
Node *delete_node(Node *root, int key)
{
    if(root == NULL)
    {
        return root;
    }

    // If the key to delete is smaller, delete on left
    if(key < root->data)
    {
        root->left = delete_node(root->left, key);
    }

    // If it is greater we need to delete on right
    if(key > root->data)
    {
        root->right = delete_node(root->right, key);
    }

    else
    {
        // Handle all the three cases.
        // 1. Node with only one child
        // Either it will be on right or left.
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node has 2 children.
        // Get the inorder sucessor.
        // Smallest in the right subtree.

        Node *temp = minValue(root->right, key);

        // Copy the inorder
        // sucessor's content to this node.
        root->data = temp->data;

        root->right = delete_node(root->right, temp->data);
    }
    return root;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}



