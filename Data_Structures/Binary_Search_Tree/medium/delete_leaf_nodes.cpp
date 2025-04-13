// https://leetcode.com/problems/delete-leaves-with-a-given-value/

// Given a binary tree root and an integer target, delete all the leaf nodes with value target.
// Note that once you delete a leaf node with value target, if its parent node becomes a leaf 
// node and has the value target, it should also be deleted (you need to continue doing that until you cannot).


// Input: root = [1,2,null,2,null,2], target = 2
// Output: [1]
// Explanation: Leaf nodes in green with value (target = 2) are removed at each step.

// Input: root = [1,2,3,2,null,2,4], target = 2
// Output: [1,null,3,null,4]
// Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
// After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).


// Definition for a binary tree node.
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
    
        // As we need to remove a parent if it becomes a leaf, we need to process children first, 
        // then "visit" the parent (post-order traversal).
        TreeNode* removeLeafNodes(TreeNode* root, int target) {
            if(root == nullptr) {
                return root;
            }
    
            root->left = removeLeafNodes(root->left, target);
            root->right = removeLeafNodes(root->right, target);
    
            if(root->val == target && root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
    
            return root;
        }
    };
