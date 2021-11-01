// https://leetcode.com/problems/binary-tree-level-order-traversal/
// Level order traversal of a tree is breadth first traversal for the tree. 
//                1
//             2     3
//           4   5
// 
// 
// Level order traversal of the tree 1 2 3 4 5.
// 
// 

// Solution: -
// Same approach as BFS is done in a graph.
// Keep a queue q.
// Push the root to the q.
// While q is not empty 
// Print the data.
// enqueue the left child, 
// enqueue the right child.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};

// This simply return a BFS.
// E.g. [3, 9, 20, 15, 7]

vector<int> print_level_order(Node *root)
{
    vector<int> res;

    if(root == NULL)
    {
        return res;
    }
    
    queue <Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        res.push_back(node->data);
        q.pop();

        // This does level order traversal, left to right.
        // Exchange the conditions to get right to left traversal.
        if(node->left != NULL)
        {
            q.push(node->left);
        }

        if(node->right != NULL)
        {
            q.push(node->right);
        }
    }
    return res;
}

// To get even the information of level
// E.g. [[3], [9, 20], [15, 7]]
// We need an extra loop
// Simply reverse the result if reversse is needed.

vector<vector<int>> print_level_order2(Node *root)
{
    vector<vector<int>> res;
            
    if(root == NULL)
    {
        return res;
    }
    
    queue <Node *> q;
    q.push(root);
    
    while(!q.empty())
    {
        int len = q.size();
        vector <int> temp;
        
        for(int i=0; i<len; i++)
        {
            Node* node = q.front();

            temp.push_back(node->data);
            q.pop();

            if(node->left != NULL)
            {
                q.push(node->left);
            }
            if(node->right != NULL)
            {
                q.push(node->right);
            }
        }
        res.push_back(temp);
    }
    return res;
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

    cout<<"Level order traversal of tree = "<<endl;
    auto res = print_level_order(root);
    cout<<endl;


    return 0;
}

