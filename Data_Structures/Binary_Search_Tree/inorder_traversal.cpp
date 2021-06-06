// We can use iterative inorder traversal trick
// This helps to solve many BST problems.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        Node *left, *right;
        int data;
};


vector <int> inorder_traversal(Node *root)
{
    vector <int> res;
    if(root == NULL)
    {
        return res;
    }

    stack <Node*> stk;

    // While we don't reach the end or we have items to traverse
    while (root != NULL || !stk.empty())
    {
        while (root != NULL)
        {
            stk.push(root);
            // left traversal done.
            root = root->left;
        }

        // Now traverse these elements.
        root = stk.top();
        stk.pop();
        // This will add left and middle.
        res.push_back(root->data);
        // Now traverse right elements.
        root = root->right;
    }
    return res;
}
