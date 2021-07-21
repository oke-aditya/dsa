// https://leetcode.com/problems/house-robber-ii/

// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed. 
// All houses at this place are arranged in a circle. 
// That means the first house is the neighbor of the last one. 
// Meanwhile, adjacent houses have a security system connected, 
// and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount 
// of money of each house, 
// return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

// Solution: -
// This is just a modification of house robber1.
// Here since they are in circle, we can either rob first house or the last house.
// We use the same hosue robber solution 2x.


#include<bits/stdc++.h>
using namespace std;

int rob_bu(vector<int> nums)
{
    int n = nums.size();
    int dp[n+1];

    // Can't rob if no houses
    dp[0] = 0;

    // If only 1 house
    dp[1] = nums[0];

    for(int i=2; i<=n; i++)
    {
        // Rob one and skip 2 or rob none
        dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
    }

    return dp[n];

}


int rob(vector <int> nums)
{
    // Edge case
    // No houses
    if(nums.size() == 0)
        return 0;

    // 1 house
    if(nums.size() == 1)
        return nums[0];
    
    // 2 houses. We can rob either
    if(nums.size() == 2)
        return max(nums[0], nums[1]);
    
    // Exclude last house, include the first.
    vector <int> v1(nums.begin(), nums.end()-1);

    // Include the first hosue, exclude the last
    vector <int> v2(nums.begin()+1, nums.end());

    return max(rob_bu(v1), rob_bu(v2)); 

}


