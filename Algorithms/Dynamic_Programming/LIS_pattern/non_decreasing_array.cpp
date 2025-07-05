// https://leetcode.com/problems/non-decreasing-array/description/

// Given an array nums with n integers, your task is to check if it 
// could become non-decreasing by modifying at most one element.
// We define an array is non-decreasing if nums[i] <= nums[i + 1] 
// holds for every i (0-based) such that (0 <= i <= n - 2).

// Example 1:

// Input: nums = [4,2,3]
// Output: true
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

// Example 2:

// Input: nums = [4,2,1]
// Output: false
// Explanation: You cannot get a non-decreasing array by modifying at most one element.

// Solution:
// Find the LIS; if it matches n -1 or n
// 


#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int lis = 0, n = nums.size();

        vector<int> dp(n, 1);

        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>i; j--) {
                if(nums[j] >= nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        lis = *max_element(begin(dp), end(dp));
        // cout<<lis;

        // return of length of LIS == n - 1;
        return (lis == n - 1 || lis == n);

    }
};