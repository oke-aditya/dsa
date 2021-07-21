// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed, the only constraint 
// stopping you from robbing each of them is that adjacent houses have 
// security systems connected and it will automatically contact the police 
// if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, 
// return the maximum amount of money you can rob tonight without alerting the police.


// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// Solution: -
// 
// A robber has 2 options: a) rob current house i; b) don't rob current house.
// If an option "a" is selected it means she can't rob previous i-1 house 
// but can safely proceed to the one before previous i-2 and gets all cumulative loot that follows.
// If an option "b" is selected the robber gets all the possible loot from robbery of i-1 and all the following buildings.
// 
// robbery of current house + loot from houses before the previous
// loot from the previous house robbery and any loot captured before that
// 
// rob(i) = max( rob(i - 2) + currentHouseValue, rob(i - 1) )


#include<bits/stdc++.h>
using namespace std;

int rob_rec(vector <int> nums, int n)
{
    // No house to rob
    
    if(n <= 0)
        return 0;
    
    // Don't rob and go 1 step back or rob and go 2 steps back
    return max(rob_rec(nums, n-1), nums[n-1] + rob_rec(nums, n-2));

}

// Simply memoize this

int dp[100];

int rob_rec_mem(vector <int> nums, int n)
{
    if(n <= 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = max(rob_rec_mem(nums, n-1), nums[n-1] + rob_rec(nums, n-2));
    return dp[n];

}

// Bottom up solution

int rob_rec_bu(vector <int> nums, int n)
{
    int dp[n+1];

    // Edge case
    // No house to rob.
    dp[0] = 0;

    // If there is just one house to rob. grab it
    dp[1] = nums[0];

    for(int i=2; i<=n; i++)
    {
        dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
    }
    
    return dp[n];

}

