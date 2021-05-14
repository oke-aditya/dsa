// Write Code to Determine if Two Trees are Identical

// Two trees are identical when they have same data and arrangement of data is also same.

// Two trees are identical when they have same data and arrangement
// of data is also same. To identify if two trees are identical
// we need to traverse both trees simultaneously, and while
// traversing we need to compare data and children of the trees.

// The idea is to use level order traversal. We traverse both
// trees simultaneously and compare the
// data whenever we dequeue and item from queue.
// Below is the implementation of the idea

// Iterative approach to it
// 
// Solution: -
// Do iterative Inorder (BFS) traversal
// We will check if each node matches.
// If it does not then return false.



#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;

};

bool are_identical(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if(root1 == NULL)
    {
        return false;
    }

    if(root2 == NULL)
    {
        return false;
    }

    // Iterative Inorder traversal BFS
    queue<Node*> q1;
    queue<Node*> q2;

    q1.push(root1);
    q2.push(root2);

    // BFS
    while(!(q1.empty() && q2.empty()))
    {
        Node *n1 = q1.front();
        Node *n2 = q2.front();

        // Not same
        if(n1->data != n2->data)
        {
            return false;
        }

        q1.pop();
        q2.pop();

        // Check for left child
        if(n1->left && n2->left)
        {
            q1.push(n1->left);
            q2.push(n2->left);
        }

        else if(n1->left || n2->left)
        {
            return false;
        }

        // Similarly for right child
        else if(n1->right && n2->right)
        {
            q1.push(n1->right);
            q2.push(n2->right);
        }

        else if(n1->right || n2->right)
        {
            return false;
        }
    }

    return true;

}



int main(int argc, char const *argv[])
{
    
    return 0;
}


