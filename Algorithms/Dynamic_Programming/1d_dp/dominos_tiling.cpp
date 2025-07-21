// https://leetcode.com/problems/domino-and-tromino-tiling/description

// You have two types of tiles: a 2 x 1 domino shape and a tromino shape. 
// You may rotate these shapes.
// Given an integer n, return the number of ways to tile an 2 x n board. 
// Since the answer may be very large, return it modulo 109 + 7.
// In a tiling, every square must be covered by a tile. 
// Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

// Example 1:
// Input: n = 3
// Output: 5
// Explanation: The five different ways are show above.

// Example 2:
// Input: n = 1
// Output: 1

// Solution:
// Trick here is to identify pattern
// For any tiling problem, focus on seeing the pattern
// Write the answers for first 5 on paper, and see pattern
// Here the pattern was 2 * (i -1) + (i - 3)


#include<vector>
using namespace std;

class Solution {
    public:
        int numTilings(int n) {
            vector<long long> dp(1000 + 1);
            dp[0] = 1;
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 5;
            dp[4] = 11;
            dp[5] = 24;
    
            for(int i=4; i<=n; i++) {
                dp[i] = dp[i - 1] * 2 + dp[i - 3];
                dp[i] %= 1000000007;
            }
    
            return dp[n];
    
        }
    };
 
