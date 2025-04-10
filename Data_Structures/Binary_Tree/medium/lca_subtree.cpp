// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/

// Given the root of a binary tree, the depth of each node is the shortest distance to the root.
// Return the smallest subtree such that it contains all the deepest nodes in the original tree.
// A node is called the deepest if it has the largest depth possible among any node in the entire tree.
// The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

// Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

// Recall that:

// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
// The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation: We return the node with value 2, colored in yellow in the diagram.
// The nodes coloured in blue are the deepest leaf-nodes of the tree.
// Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.

// Example 2:

// Input: root = [1]
// Output: [1]
// Explanation: The root is the deepest node in the tree, and it's the lca of itself.

// Example 3:

// Input: root = [0,1,3,null,2]
// Output: [2]
// Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.

// solution:
// first get the max depth
// nodes at max_depth -1  are the answers
// if we have reached the bottom, then for leaf nodes, their root is the answer
// It's very tricky do on pen and paper


#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    public:
    
        int max_depth(TreeNode *root) {
            if(root == nullptr) {
                return 0;
            } 
    
            int left_depth = 1 + max_depth(root->left);
            int right_depth = 1 + max_depth(root->right);
            return max(left_depth, right_depth);
        }
    
        TreeNode* dfs(TreeNode* root, int counter, int max_depth) {
            if(root == nullptr) {
                return root;
            }
    
            if(counter == (max_depth - 1)) {
                return root;
            }
    
            TreeNode* left = dfs(root->left, counter+1, max_depth);
            TreeNode* right = dfs(root->right, counter+1, max_depth);
    
            // we have reached the leaft
            if(left != nullptr && right != nullptr) {
                return root;
            }
    
            if(left != nullptr) {
                return left;
            }
            else {
                return right;
            }
    
            return root;
    
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            // find the maximum depth
    
            int maxd = max_depth(root);
            cout<<maxd;
    
            // do a dfs till maxd - 1;
    
            return dfs(root, 0, maxd);
    
    
        }
    };


