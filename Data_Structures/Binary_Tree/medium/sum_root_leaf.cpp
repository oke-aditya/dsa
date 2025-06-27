// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

// You are given the root of a binary tree containing digits from 0 to 9 only.
// Each root-to-leaf path in the tree represents a number.
// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
// A leaf node is a node with no children.

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

    int dfs(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
    
        if(root->left == nullptr && root->right == nullptr) {
            return sum * 10 + root->val;
        }

        return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

