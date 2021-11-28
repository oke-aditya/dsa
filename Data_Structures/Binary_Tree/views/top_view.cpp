// Top view of a binary tree is the set of nodes visible when the tree is 
// viewed from the top. 
// Given a binary tree, print the top view of it.
//  Note: Return nodes from leftmost node to rightmost node.

// Input:
//       1
//    /    \
//   2      3

// // Output: 2 1 3

// Input:
//        10
//     /      \
//   20        30
//  /   \    /    \
// 40   60  90    100

// Output: 40 20 10 30 100

// Very similar to bottom view.

// Solution: -
// We need to use the concept of horizontal distance here. 
// Whenever we move in the left direction of a node, we subtract
// from the horizontal distance of the current node. Similarly,
// if we move in the right direction, we add 1 to horizontal distance.
// Once we are familiar with this concept.
// We will use a map to keep track of nodes at each of the horizontal distance.
// *** ****
// Here unlike bottom view, we need to keep the track of
// *** 
// Here we will update the map with line only if it wasn't found before.
// We need topmost not the last one.
// ****
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

vector<int> top_view(Node *root)
{
    vector<int> res;

    if(root == NULL)
    {
        return res;
    }

    // Map to line and data of node.
    map<int, int> mp;

    // BFS
    // q to store line and Node.
    queue <pair<int, Node *>> q;

    // Root has 0 horizontal depth.
    q.push({0, root});

    while (!q.empty())
    {
        int line = q.front().first; 
        Node *node = q.front().second;

        q.pop();

        if(mp.find(line) == mp.end())
            mp[line] = node->data;

        if(node->left)
            q.push({line - 1 , node->left});
        
        if(node->right)
            q.push({line + 1, node->right});

    }

    for(auto x: mp)
        res.push_back(x.second);

    return res;

}

