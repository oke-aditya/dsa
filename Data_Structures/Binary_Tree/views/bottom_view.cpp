// Given a Binary Tree, we need to print the bottom view from left to right.
// A node x is there in output if x is the bottommost node at
// its horizontal distance. Horizontal distance of left child
// of a node x is equal to horizontal distance of x minus 1,
// and that of right child is horizontal distance of x plus 1.

//         20
//     /    \
//     8       22
// /   \      \
// 5      3      25
//     / \      
//     10    14

// For the above tree the output should be 5, 10, 3, 14, 25.

// Solution: -
// We need to use the concept of horizontal distance here. 
// Whenever we move in the left direction of a node, we subtract
// from the horizontal distance of the current node. Similarly,
// if we move in the right direction, we add 1 to horizontal distance.
// Once we are familiar with this concept.
// We will use a map to keep track of nodes at each of the horizontal distance.
// Then we will traverse the tree and whenever we find a node we update our map.
// We will keep the horizontal distance as key and the node as the value to the map.
// So using a level order traversal, keep calculating the horizontal distance and updating the map.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
};

vector<int> bottom_view(Node *root)
{
    vector<int> res;

    if(root == NULL)
    {
        return res;
    }

    // Map to line and data of node.
    map<int, int> mp;

    // BFS
    queue <pair<int, Node *>> q;

    // Root has 0 horizontal depth.
    q.push({0, root});

    mp[0] = root->data;

    while(!q.empty())
    {
        pair<int, Node*> node_pr = q.front();   

        q.pop();

        Node *node = node_pr.second;
        int line = node_pr.first;

        mp[line] = node->data;
        
        if(node->left)
        {
            q.push({line - 1, node->left});
        }

        if(node->right)
        {
            q.push({line + 1, node->right});
        }
    }

    vector<int> res;
    for(auto x: mp)
    {
        res.push_back(x.second);
    }

}


