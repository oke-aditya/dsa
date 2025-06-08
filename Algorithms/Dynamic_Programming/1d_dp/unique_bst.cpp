// https://leetcode.com/problems/unique-binary-search-trees/
// Given an integer n, return the number of structurally unique BST's 
// (binary search trees) which has exactly n nodes of unique values from 1 to n.

// Example 1:

// Input: n = 3
// Output: 5

// Example 2:

// Input: n = 1
// Output: 1

// Solution
// https://www.cs.cmu.edu/afs/cs/academic/class/15750-s17/ScribeNotes/lecture7.pdf
// This is a classic CMU DS Algo problem
// Fix the root as this is a BST
// left would have j elements, then right would have (n - j - 1) elements
// Both of these could be independent, hence we will have j * (n - j - 1) combinations
// Each of these could then be summed to given unique options. Hence the relation Sum(j * (n - j -1)) from 0 to n


#include<vector>
using namespace std;

class Solution {
public:

    // https://www.cs.cmu.edu/afs/cs/academic/class/15750-s17/ScribeNotes/lecture7.pdf
    int numTrees(int n) {
        // we have 1 state that is n
        vector<int> dp(20, 0);

        // one way to create tree of 0 nodes
        dp[0] = 1;

        // one way to create tree of 1 node
        dp[1] = 1;

        // 2 ways to create tree of 2 nodes
        dp[2] = 2;

        for(int i=3; i<=19; i++) {
            for(int j=0; j<i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[n];

    }
};
