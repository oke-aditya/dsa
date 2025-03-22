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

#include <bits/stdc++.h>

using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums) {
  sort(begin(nums), end(nums));

  int n = nums.size(), prev = -1, maxi = -1;
  vector<int> dp(n + 1);

  for (int i = 0; i < n; i++) {
    for (int prev = 0; prev < i; prev++) {
      // same as LCS but this is the condiiton to check
      if (nums[i] % nums[prev] == 0) {
        dp[i] = max(dp[i], 1 + dp[prev]);
      }
    }
    maxi = max(maxi, dp[i]);
  }

  vector<int> res;
  prev = -1;

  for (int i = n - 1; i >= 0; i--) {
    // extra thing to check as we want to keep only divisble elements.
    if (dp[i] == maxi && (prev == -1 || prev % nums[i] == 0)) {
      res.push_back(nums[i]);
      maxi -= 1;
      prev = nums[i];
    }
  }

  reverse(begin(res), end(res));
  return res;
}