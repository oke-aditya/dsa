// https://leetcode.com/problems/delete-node-in-a-bst/description/

// Given a Binary Search Tree and a node value X.
// Delete the node with the given value X from the BST.
// If no node with value x exists, then do not make any change.
// Input:
//             1
//              \
//               2
//                 \
//                  8
//                /    \
//               5      11
//             /  \    /  \
//            4    7  9   12
// X = 9
// Output: 1 2 4 5 7 8 11 12
// Explanation: In the given input tree after
// deleting 9 will be

#include <bits/stdc++.h>
using namespace std;

// Solution: -
// When we delete a node, three possibilities arise.

// 1) Node to be deleted is the leaf: Simply remove from the tree.

//               50                            50
//            /     \         delete(20)      /   \
//           30      70       --------->    30     70
//          /  \    /  \                     \    /  \ 
//        20   40  60   80                   40  60   80

// 2) Node to be deleted has only one child: Copy the child to the node and
// delete the child

//               50                            50
//            /     \         delete(30)      /   \
//           30      70       --------->    40     70
//             \    /  \                          /  \ 
//             40  60   80                       60   80

// 3) Node to be deleted has two children:
// Find inorder successor of the node. Copy contents of the inorder successor
// to the node and delete the inorder successor. Note that inorder predecessor
// can also be used.

//               50                            60
//            /     \         delete(50)      /   \
//           40      70       --------->    40    70
//                  /  \                            \ 
//                 60   80   /**
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

    int find_min_from_right(TreeNode* root) {
        while(root->left != nullptr) {
            root = root->left;
        }
        return root->val;

    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == nullptr) {
            return root;
        }
        
        // we need to delete this target node.
        if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // key == root->val
        else {
            // if we have no children
            if(root->left == nullptr && root->right == nullptr) {
                delete(root);
                return nullptr;
            }
            // one child that is left
            else if(root->right == nullptr) {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            // one child that is right
            else if(root->left == nullptr) {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            // we have case where we have both the children
            // we need the minimum value from right of this subtree
            else {
                root->val = find_min_from_right(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }

        return root;
    }
};