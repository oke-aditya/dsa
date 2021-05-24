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
// Use a Queue 
// 1. We put tree nodes in a queue for the level order traversal. 
// 2. Start with the horizontal distance(hd) 0 of the root node,
// keep on adding left child to queue along with the horizontal distance as hd-1 and right child as hd+1. 
// 3. Also, use a Map which stores key value pair sorted on key. 
// 4. Every time, we encounter a new horizontal distance or an existing
// horizontal distance put the node data for the horizontal distance as key.
// For the first time it will add to the map, next time it will replace
// the value. This will make sure that the bottom most element
// for that horizontal distance is present in the map and if
// you see the tree from beneath that you will see that element.
// 

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

    map<int, int> mp;
    


    // Map contains key value of depths.
    for(auto itr=mp.begin(); itr!= mp.end(); itr++)
    {
        res.push_back(itr->second);
    }
    return res;

}


