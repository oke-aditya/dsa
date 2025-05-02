// https://leetcode.com/problems/most-frequent-subtree-sum/description/?

// Given the root of a binary tree, return the most frequent subtree sum. 
// If there is a tie, return all the values with the highest frequency in any order.
// The subtree sum of a node is defined as the sum of all the node values formed 
// by the subtree rooted at that node (including the node itself).

// Solution:
// Just calculate the left sum and right sum using DFS.
// store in map and return max freq.

#include<unordered_map>
#include<vector>
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
    
        int dfs(TreeNode* root, unordered_map<int, int> &mp) {
            if(root == nullptr) {
                return 0;
            }
    
            int lsum = dfs(root->left, mp);
            int rsum = dfs(root->right, mp);
            
            mp[root->val + lsum + rsum] += 1;
            return root->val + lsum + rsum;
    
        }
    
        vector<int> findFrequentTreeSum(TreeNode* root) {
            unordered_map<int, int> mp;
            dfs(root, mp);
    
            int max_freq = 0;
            for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
                max_freq = max(max_freq, itr->second);
            }
    
            vector<int> res;
            for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
                if(itr->second == max_freq) {
                    res.push_back(itr->first);
                }
            }
            return res;
    
        }
    };
