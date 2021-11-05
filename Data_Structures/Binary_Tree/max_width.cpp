// https://leetcode.com/problems/maximum-width-of-binary-tree/
// https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/727354/C%2B%2B-or-O(n)-intuitive-BFS-solution-using-Queue-or-Detailed-Explanation

// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes 
// (the leftmost and rightmost non-null nodes), where 
// the null nodes between the end-nodes are also counted into the length calculation.

// It is guaranteed that the answer will in the range of 32-bit signed integer.

// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

// Input: root = [1,3,2,5,null,null,9,6,null,null,7]
// Output: 8
// Explanation: The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).

// Solution: -
// Nodes at level n can be 2 ^ n. So this means we need to handle integer overflow.
// Even 20 nodes can make 2 ^ 20 = 10 ^ 6.
// We need to do a simple BFS. and find number of nodes at the level.

#include<bits/stdc++.h>
using namespace std;

class Node 
{
    public:
        int data;
        Node *left, *right;
};

// Inserts only the 
// non-NULL nodes in the queue along with their indices in the tree. 
// The index of the left and right child nodes are 2*parent_index + 1 and 2*parent_index + 2 
// respectively. 
// Thus, the space and time required to process the
//  NULL nodes earlier being pushed into the deque is eliminated.

int widthOfBinaryTree(Node* root) 
{
    int max_width = 0;

    if(root == NULL)
        return max_width;

    queue <pair<Node *, int>> q;
    q.push({root, 0});
    
    // Plain BFS
    while (!q.empty())
    {
        int left_index = q.front().second;
        int right_index = 0;
        int n = q.size();

        for(int i=0; i<n; i++)
        {
            pair<Node *, int> pr = q.front();
            q.pop();
            Node *node = pr.first;
            int right_index = pr.second;

            if(node->left)
                q.push({node->left, 2 * right_index + 1});

            if(node->right)
                q.push({node->right, 2 * right_index + 2});
        }
        max_width = max(max_width, right_index - left_index + 1);
    }

    return max_width;

}


