// https://leetcode.com/problems/recover-binary-search-tree/description/

// You are given the root of a binary search tree (BST), where the values of 
// exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 
// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>
#include <climits>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode *first_mistake = nullptr, *second_mistake = nullptr, *prev;

    void dfs(TreeNode *root) {
        if(root == nullptr)
            return;
        
        dfs(root->left);
        
        // this is wrong
        // previous value should always be smaller
        if(first_mistake == nullptr && root->val < prev->val) {
            first_mistake = prev;
        }
        
        // wrong again. This time the root is wrong.
        if(first_mistake != nullptr && root->val < prev->val) {
            second_mistake = root;
        }
        
        prev = root;

        dfs(root->right);
    }


    void recoverTree(TreeNode* root) {
        // do an inorder traversal
        prev = new TreeNode(INT_MIN);
        dfs(root);

        swap(first_mistake->val, second_mistake->val);
        

    }
};

