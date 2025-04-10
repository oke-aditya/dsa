// https://leetcode.com/problems/balanced-binary-tree/
// Given a binary tree, determine if it is height balanced

#include<algorithm>
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
    
        int height(TreeNode* root) {
            if(root == nullptr) {
                return 0;
            }
    
            int l_h = 1 + height(root->left);
            int r_h = 1 + height(root->right);
            return max(l_h, r_h);
        }
    
    
        bool isBalanced(TreeNode* root) {
            if(root == nullptr) {
                return true; 
            }
    
            int left_height = height(root->left);
            int right_height = height(root->right);
    
            return isBalanced(root->left) && isBalanced(root->right) && abs(left_height-right_height) <= 1;
        }
    };

