// https://leetcode.com/problems/binary-subarrays-with-sum/description/
// Given a binary array nums and an integer goal, return the number of non-empty
// subarrays with a sum goal. A subarray is a contiguous part of the array.

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]

// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15

// Remember our trick to calculate sum of it's less than K?
// We use that trick for both k and k-1. Difference is the result.

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int helper(vector<int>& nums, int goal) {
    if (goal < 0) {
      return 0;
    }
    int i = 0, j = 0;
    int curr_sum = 0, n = nums.size(), count = 0;

    for (j = 0; j < n; j++) {
      curr_sum += nums[j];

      while (curr_sum > goal) {
        curr_sum -= nums[i];
        i += 1;
      }

      count += (j - i) + 1;
    }
    return count;
  }

  int numSubarraysWithSum(vector<int>& nums, int goal) {
    return helper(nums, goal) - helper(nums, goal - 1);
  }
};
