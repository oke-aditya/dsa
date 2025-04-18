// https://leetcode.com/problems/house-robber-ii/

// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
// That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, 
// and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, 
// return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), 
// because they are adjacent houses.

// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 3:

// Input: nums = [1,2,3]
// Output: 3

#include<vector>
using namespace std;

class Solution {
    public:
    
        int rob_bu(vector<int> &nums) {
            int n = nums.size();
            vector<int> dp(n, 0);
    
            // if we have just 1 house
            dp[0] = nums[0];
    
            // we have 2 houses
            dp[1] = max(nums[0], nums[1]);
    
            for(int i=2; i<n; i++) {
                dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
            }
    
            return dp[n-1];
    
        }
    
        int rob(vector<int>& nums) {
            int n = nums.size();
    
            if(n == 0) {
                return 0;
            }
    
            else if(n == 1) {
                return nums[0];
            }
    
            else if(n == 2) {
                return max(nums[0], nums[1]);
            }
    
            vector<int> rob1 = vector<int>(nums.begin(), nums.end()-1);
            vector<int> rob2 = vector<int>(nums.begin() + 1, nums.end());
    
            return max(rob_bu(rob1), rob_bu(rob2));
    
    
        }
    };