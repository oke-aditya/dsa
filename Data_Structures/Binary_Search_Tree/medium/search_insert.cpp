// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

// You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
// Return the root node of the BST after the insertion. 
// It is guaranteed that the new value does not exist in the original BST.

// Notice that there may exist multiple valid ways for the insertion, 
// as long as the tree remains a BST after insertion. You can return any of them.


#include <bits/stdc++.h>
using namespace std;


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
      TreeNode* insertIntoBSTRec(TreeNode* root, int val) {
          if(root == nullptr) {
              return new TreeNode(val);
          }
  
          if(val > root->val) {
              root->right = insertIntoBSTRec(root->right, val);
          }
  
          else {
              root->left = insertIntoBSTRec(root->left, val);
          }
  
          return root;
      }
  
  };


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
 class Solution2 {
  public:
      TreeNode* insertIntoBST(TreeNode* root, int val) {
          
          TreeNode* node = root;
          TreeNode* new_node = new TreeNode(val);
  
          if(root == nullptr) {
              return new_node;
          }
          
          while(true) {
              if(node->val > val) {
                  if(node->left != nullptr) {
                      node = node->left;
                  }
                  else {
                      node->left = new_node;
                      break;
                  }
              }
              else {
                  if(node->right != nullptr) {
                      node = node->right;
                  }
                  else {
                      node->right = new_node;
                      break;
                  }
              }
          }
          return root;
  
      }
  
  };  