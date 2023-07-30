// https://leetcode.com/problems/min-cost-climbing-stairs

// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

 

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.

#include <bits/stdc++.h>
using namespace std;



int helper(vector<int> cost, int n, vector<int> &dp)
{
    
    if(n <= 1)
    {
        return cost[n];
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = cost[n] + min(helper(cost, n-1, dp), helper(cost, n-2, dp));
    return dp[n];
        // return cost[n] + min(helper(cost, n-1), helper(cost, n-2));
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+2, -1);

    int res = min(helper(cost, n-1, dp), helper(cost, n-2, dp));

    return res;
}

int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, -1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<n; i++)
        {
            // cout<<i;
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        // return 0;

        return min(dp[n-1], dp[n-2]);

        // int res = min(helper(cost, n-1, dp), helper(cost, n-2, dp));

        // return res;
}