// https://leetcode.com/problems/perfect-squares/description/

// Given an integer n, return the least number of perfect square numbers that sum to n.
// A perfect square is an integer that is the square of an integer; in other words, 
// it is the product of some integer with itself. For example, 1, 4, 9, and 16 are 
// perfect squares while 3 and 11 are not.

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.

// Solution
// This is very similar to coin chance, we need to know number of integers that can be used to get n.
// Initially we need all squares upto n, then we can estimate

#include <climits>
#include<vector>
using namespace std;

class Solution {
    public:
        int numSquares(int n) {
            vector<int> dp(n + 1, INT_MAX);
            dp[0] = 0;

            // for ever number n, 
            for(int i=1; i<=n; i++) {
                for(int j=1; j*j <=n; j++) {
                    int temp = j * j;
                    if(i - temp >= 0) {
                        dp[i] = min(dp[i], 1 + dp[i - temp]);
                    }
                }
            }
            return dp[n];
        }
    };