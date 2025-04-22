// https://leetcode.com/problems/largest-divisible-subset/
//
// Given a set of distinct positive integers nums, return the largest subset
// answer such that every pair (answer[i], answer[j]) of elements in this subset
// satisfies:

//     answer[i] % answer[j] == 0, or
//     answer[j] % answer[i] == 0

// If there are multiple solutions, return any of them.
//
// Example 1:
//
// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.

// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]

// Solution: 
// This is classic LCS Question
// Think of it as Longest Divisible Subset
// instead of increasing, we need to check divisibility.
// Once we have the length of longest divisible subset
// we can the print it out


#include <bits/stdc++.h>

using namespace std;

void print_v(vector<int> v) {
  for(auto i: v) {
      cout<<i<<" ";
  }
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
  sort(begin(nums), end(nums));

  vector<int> res;
  int n = nums.size();
  vector<int> dp(n, 1);

  for(int i=n-1; i>=0; i--) {
      for(int j=n-1; j>i; j--) {
          // cout<<"i: "<<i<<" j: "<<j<<endl;
          if(nums[j] % nums[i] == 0) {
              dp[i] = max(dp[i], 1 + dp[j]);
          }
      }
  }

  // print_v(dp);
  // use the max value to do print it
  int maxi = *max_element(begin(dp), end(dp));
  int prev = -1;
  for(int i=0; i<n; i++) {
      if(dp[i] == maxi && (nums[i] % prev == 0 || prev == -1)) {
          res.push_back(nums[i]);
          maxi -= 1;
          prev = nums[i];
      }
  }

  return res;
}