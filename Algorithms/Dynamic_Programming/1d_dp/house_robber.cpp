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

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// Think iterative directly
// If there is just one house to rob we can take it 
// If there are 2 houses to rob, we can take max of either
// Otherwise we have to make a choice, to rob this house nums[i] and 2 previous or pick the previous best house.


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
      int rob(vector<int>& nums) {
          int n = nums.size();
          
          if(n == 1) {
              return nums[0];
          }
  
          vector<int> dp(n, 0);
  
          dp[0] = nums[0];
          dp[1] = max(nums[0], nums[1]);
          
          for(int i=2; i<n; i++) {
              // rob or avoid
              dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
          }
  
          return dp[n-1];
  
      }
  };