//  Count Partitions With Given Difference

// You are given an array 'arr' of size 'n'  containing positive integers and a
// target sum 'k'. Find the number of ways of selecting the elements from the
// array such that the sum of chosen elements is equal to the target 'k'.

// Input: N = 4, D = 3, ARR = {5, 2, 5, 1}

// Output: 3

// There are only two possible partitions of this array.
// Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5
// + 2 + 1) - (5) = 3 Partition 2: {5, 2, 1}, {5}. The subset difference between
// subset sum is: (5 + 2 + 1) - (5) = 3 These two partitions are different
// because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd
// partition, S1 contains 5 from index 2.

// subset(1) + subset(2) = total --- (1)
// subset(1) - subset(2) = target --- (2)
// [Adding equations (1) and (2)]
// 2 * subset(1) = total - target
// subset(1) = ( total - target) / 2

#include <bits/stdc++.h>
using namespace std;

int subset_sum(vector<int> nums, int sum, int n) {
  // // base conditions
  if (n == 0) {
    if (sum == 0) {
      return 1;
    }
    return 0;
  }

  else {
    if (nums[n - 1] > sum) {
      // can't pick
      return subset_sum(nums, sum, n - 1);
    } else {
      // pick / can't pick
      return subset_sum(nums, sum - nums[n - 1], n - 1) +
             subset_sum(nums, sum, n - 1);
    }
  }
}

// Because range of the sum includes 0.
// Ex - If all the elements are 0 and we want a sum 0, for that we need j from
// 0. So that 0 can also be considered as sum of previous subset of i elements.

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
  return subset_sum(nums, new_sum, n);
}

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