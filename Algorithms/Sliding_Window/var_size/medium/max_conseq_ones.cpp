// https://leetcode.com/problems/max-consecutive-ones-iii/description/

// Given a binary array nums and an integer k, return the maximum number of
// consecutive 1's in the array if you can flip at most k 0's.

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

#include <bits/stdc++.h>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
  int zero_count = 0, i = 0, j = 0;
  int max_len = 0;
  int n = nums.size();

  for (int j = 0; j < n; j++) {
    if (nums[j] == 0) {
      zero_count += 1;
    }

    while (zero_count > k) {
      if (nums[i] == 0) {
        zero_count -= 1;
      }
      i += 1;
    }

    max_len = max(max_len, (j - i + 1));
  }

  return max_len;
}
