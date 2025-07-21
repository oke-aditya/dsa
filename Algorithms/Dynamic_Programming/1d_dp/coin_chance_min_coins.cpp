// Minimum number of coins needed for coin change.
// https://leetcode.com/problems/coin-change/description/

// You are given an integer array coins representing coins of different 
// denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. 
// If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Example 2:

// Input: coins = [2], amount = 3
// Output: -1

// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

// Solution:
// What matters here is the amount we have accumulated till now,
// The only state is amount
// We should evaluate each amount if it is possible or not
// finally return the state of amount
// initially amount[0] = 0, since we need 0 coins do 0 amount
// for uesful coins, coins[j] <= i
// the dp state is either using this coin, or not using it
// if we use this coin then the amount will reduce by coins[j] and coins will be + 1;


#include <climits>
#include<vector>
using namespace std;

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            
            // dp of amount + 1 size, with INT_MAX
            vector<int> dp(amount+1, INT_MAX);
            dp[0] = 0;
            int n = coins.size();

            for(int i=1; i<=amount; i++) {
                for(int j=0; j<n; j++) {
                    // this coin < amount, useful coin
                    // otherwise coin is useless
                    if(coins[j] <= i) {
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                    
                }
            }

            
            // not possible to reach the amount
            if(dp[amount] == INT_MAX) {
                return -1;
            }

            return dp[amount];
            
    }
};


