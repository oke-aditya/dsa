// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children 
// will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. 
// The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a 
// list of top-to-bottom orderings for each column index 
// starting from the leftmost column and ending on the 
// rightmost column. There may be multiple nodes in the same row and same column. 
// In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.

// Input: root = [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
// Explanation:
// Column -1: Only node 9 is in this column.
// Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
// Column 1: Only node 20 is in this column.
// Column 2: Only node 7 is in this column.

#include<bits/stdc++.h>
using namespace std;

class Node 
{
    public:
        int data;
        Node *left, *right;
};

vector<vector<int>> verticalTraversal(Node* root) {

    // Map to store node and it's value
    map<int, map<int, multiset<int>>> mp;

    // This queue stores each element as cordinates relative to root.
    // First being how left the node is and second being how down.
    queue<pair<Node*, pair<int, int>>> todo;

    // Since root has cordinates (0, 0)
    todo.push({root, {0, 0}});

    // BFS
    while (!todo.empty())
    {
        auto pr = todo.front();
        todo.pop();

        Node *node = pr.first;

        int x = pr.second.first;
        int y = pr.second.second;
        mp[x][y].insert(node->data);


        if(node->left)
            todo.push({node->left, {x - 1, y + 1}});
        
        if(node->right)
            todo.push({node->right, {x + 1, y + 1}});
    }

    vector<vector<int>> res;

    // Since we have to return sorted result
    
    for(auto p: mp)
    {
        vector<int> col;
        for(auto ele: p.second)
        {
            col.insert(col.end(), ele.second.begin(), ele.second.end());
        }
        res.push_back(col);
    }

    return res;

}

