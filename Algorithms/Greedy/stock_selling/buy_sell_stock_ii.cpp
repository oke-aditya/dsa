// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// You are given an integer array prices where prices[i] 
// is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. 
// You can only hold at most one share of the stock at any time. 
// However, you can sell and buy the stock multiple times on the 
// same day, ensuring you never hold more than one share of the stock.

// Find and return the maximum profit you can achieve.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// Solution:

// We can greedily buy at lowest price, take profit of the delta and keep doing it.
// Whenever we earn profit, we get a new minimum

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int n = prices.size();
        int min_price = INT_MAX;

        for(int i=0; i<n; i++) {
            min_price = min(min_price, prices[i]);
            int profit = prices[i] - min_price;
            
            if(profit > 0) {
                min_price = prices[i];
                max_profit += profit;
            }
        }

        return max_profit;
    }
};