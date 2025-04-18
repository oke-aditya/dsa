// Given an integer array nums, return the length of the longest strictly
// increasing subsequence.
// https://leetcode.com/problems/longest-increasing-subsequence/

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
// length is 4.

// keep this pattern very simple
// do not overthink 2D DP or reversing the LIS etc
// THink of this array

// [1, 4, 2, 3]

// What is the LIS of last element? Obviously 1?
// What is LIS of 2nd last element? if that is smaller than elements after it, it is 1 + LIS ?
// Notice how base case offered here is from last element
// Think if we start processing from last element we can dp
// what would be LIS at 1? it could be 2 if we take path of 4, or 3 if we take path of 2
// THat is max() of lis of next elements
// LIS will look like this
// [3, 1, 2, 1]
// TC O(N2) SC O(N)

#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
  public:


      void print_v(vector<int> v) {
        for (auto x : v) {
          cout << x << " ";
        }
        cout << endl;
      }

      int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        // minimum LIS is 1
        vector<int>dp(n, 1);
        
        for(int i=n-1; i>=0; i--) {
          for(int j=n-1; j>i; j--) {
            
            if(nums[j] > nums[i]) {
              dp[i] = max(dp[i], 1 + dp[j]);
            }
          }
        }
        
        // print_v(dp);
        return *max_element(dp.begin(), dp.end());
         
      }
  };


