// Write a function to print spiral order traversal of a tree
// For below tree, function should print 1, 2, 3, 4, 5, 6, 7. 
// 
//                  1
//          2             3
//      7    6          5   4
// 


// Solution: -
// This problem can be seen as an extension of the level order traversal post. 

// We can print spiral order traversal in O(n) time and O(n) extra space.
// The idea is to use two stacks. We can use one stack
// for printing from left to right and other stack for printing from right to left.
// In every iteration, we have nodes of one level in one of the stacks. We print
// the nodes, and push nodes of next level in other stack. 


#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};

vector<int> findSpiral(Node *root)
{
    vector <int> res;
    if(root == NULL)
    {
        return res;
    }

    stack <Node*> stk1;
    stack <Node*> stk2;

    stk1.push(root);

    // Keep printing while one of them has data.
    while (!stk1.empty() || !stk2.empty())
    {
        // Print from current level s1 and push nodes to s2
        while (!stk1.empty())
        {
            Node *temp = stk1.top();
            stk1.pop();
            res.push_back(temp->data);
        
            // If elements are present on left or right
            // Note that spiral needs right before left in first half
            if(temp->right)
            {
                stk2.push(temp->right);
            }
            if(temp->left)
            {
                stk2.push(temp->left);
            }
        }

        // Print nodes of current level from s2 and push nodes of
        // next level to s1

        while (!stk2.empty())
        {
            Node *temp = stk2.top();
            stk2.pop();
            res.push_back(temp->data);

            // Note that spiral needs right before left in second half.
            if(temp->left)
            {
                stk1.push(temp->left);
            }

            if(temp->right)
            {
                stk1.push(temp->right);
            }
        }
    }
    return res;
}

