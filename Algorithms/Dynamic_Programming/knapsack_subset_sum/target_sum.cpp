// https://leetcode.com/problems/target-sum/
// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+'
// and '-' before each integer in nums and then concatenate all the integers.

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be
// target 3. -1 + 1 + 1 + 1 + 1 = 3 +1 - 1 + 1 + 1 + 1 = 3 +1 + 1 - 1 + 1 + 1 =
// 3 +1 + 1 + 1 - 1 + 1 = 3 +1 + 1 + 1 + 1 - 1 = 3

// Same answer as count_partition_same_diff.

#include <bits/stdc++.h>

using namespace std;

// Same answer as count_partition_same_diff.
int findTargetSumWays(vector<int> &nums, int target) {
  int n = nums.size();
  int sum = 0;
  for (auto it : nums) {
    sum += it;
  }

  if ((sum - target) % 2 != 0 || (sum - target) < 0) {
    return false;
  }

  int new_sum = (sum - target) / 2;

  vector<vector<int>> dp(n + 1, vector<int>(new_sum + 1, 0));
  // return subset_sum_mem(nums, n, new_sum, dp);

  // initializing first column by 1
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= new_sum; j++) {
      if (nums[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
      }
    }
  }

  return dp[n][new_sum];
}
