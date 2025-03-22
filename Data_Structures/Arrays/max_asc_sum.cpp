// Given an array of positive integers nums, return the maximum possible sum of
// an ascending subarray in nums.
// https://leetcode.com/problems/maximum-ascending-subarray-sum/

// A subarray is defined as a contiguous sequence of numbers in an array.

// A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i
// where l <= i < r, numsi < numsi+1. Note that a subarray of size 1 is
// ascending.

// Example 1:

// Input: nums = [10,20,30,5,10,50]
// Output: 65
// Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

// Example 2:

// Input: nums = [10,20,30,40,50]
// Output: 150
// Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum
// of 150.

// Input: nums = [100,10,1]
// Output: 100

#include <bits/stdc++.h>
using namespace std;

int max_asc_sum(vector<int> &nums) {
  int res = 0, sum = nums[0];

  for (auto i = 1; i < nums.size(); i++) {
    if (nums[i - 1] < nums[i]) {
      sum += nums[i];
    } else {
      res = max(sum, res);
      sum = nums[i];
    }
  }
  res = max(sum, res);
  return res;
}

int main(int argc, char const *argv[]) { return 0; }
