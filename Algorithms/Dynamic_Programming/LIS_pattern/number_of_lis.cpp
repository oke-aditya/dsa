// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

// Given an integer array nums, return the number of longest increasing
// subsequences.

// Notice that the sequence has to be strictly increasing.

// Example 1:

// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

// Solution

// Subtle variant of LIS, we need to additionally maintain count

#include <bits/stdc++.h>

using namespace std;
int findNumberOfLIS(vector<int> &nums) {
  int n = nums.size();

  vector<int> dp(n + 1, 1);

  vector<int> count(n + 1, 1);

  int maxi = 1;

  for (int i = 0; i < n; i++) {
    for (int prev = 0; prev < i; prev++) {
      if (nums[i] > nums[prev]) {
        // same as max.
        if (dp[prev] + 1 > dp[i]) {
          dp[i] = dp[prev] + 1;
          count[i] = count[prev];
        }

        else if (dp[prev] + 1 == dp[i]) {
          count[i] += count[prev];
        }
        // dp[i] = max(dp[i], 1 + dp[prev]);
      }
      maxi = max(maxi, dp[i]);
    }
  }

  int res = 0;

  // now find where the maxi is

  for (int i = 0; i < n; i++) {
    if (dp[i] == maxi) {
      res += count[i];
    }
  }
  return res;
}