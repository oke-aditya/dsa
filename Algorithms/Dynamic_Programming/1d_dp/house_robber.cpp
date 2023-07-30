// https://leetcode.com/problems/house-robber/description/

// Also applicable to Maximum Sum of non-adjacent elements

// You are a professional robber planning to rob 
// houses along a street. Each house has a certain 
// amount of money stashed, the only constraint stopping you 
// from robbing each of them is that adjacent houses have 
// security systems connected and it will automatically 
// contact the police if two adjacent houses were broken 
// into on the same night.

// Given an integer array nums representing the amount 
// of money of each house, return the maximum amount of 
// money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> nums, int n, vector<int> &dp)
{
    if(n < 0)
    {
        return 0;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    else
    {
        dp[n] = max(nums[n] + helper(nums, n-2, dp), helper(nums, n-1, dp));
        return dp[n];
    }
}

int rob(vector<int>& nums) {
    // return 1;

    int n = nums.size();
    vector<int> dp(n + 2, -1);
    int res = helper(nums, n-1, dp);
    return res;
}



int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n+2, -1);
        dp[0] = 0;
        dp[1] = nums[0];
        
        for(int i=2; i<=n; i++)
        {
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }

        return dp[n];


}
