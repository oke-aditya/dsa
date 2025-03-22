// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?

// You are given a 0-indexed array nums consisting of positive integers. You can
// choose two indices i and j, such that i != j, and the sum of digits of the
// number nums[i] is equal to that of nums[j].

// Return the maximum value of nums[i] + nums[j] that you can obtain over all
// possible indices i and j that satisfy the conditions.

// Example 1:

// Input: nums = [18,43,36,13,7]
// Output: 54
// Explanation: The pairs (i, j) that satisfy the conditions are:
// - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 +
// 36 = 54.
// - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 +
// 7 = 50. So the maximum sum that we can obtain is 54.

// Example 2:

// Input: nums = [10,12,19,14]
// Output: -1
// Explanation: There are no two numbers that satisfy the conditions, so we
// return -1.

#include <bits/stdc++.h>

using namespace std;

int compute_sum(int num) {
  // compute sum of digits
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num = num / 10;
  }
  return sum;
}

int maximumSum(vector<int>& nums) {
  // map with integer as sum of digits and max heap to store numbers.
  unordered_map<int, priority_queue<int>> mp;

  for (auto num : nums) {
    int sum_digits = compute_sum(num);
    mp[sum_digits].push(num);
  }

  int max_sum = -1;
  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    if ((itr->second).size() > 1) {
      auto maxh = itr->second;
      int f1 = maxh.top();
      maxh.pop();
      int f2 = maxh.top();
      max_sum = max(max_sum, (f1 + f2));
    }
  }

  return max_sum;
}
