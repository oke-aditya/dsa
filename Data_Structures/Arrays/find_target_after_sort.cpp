// https://leetcode.com/problems/find-target-indices-after-sorting-array/description/

// Find Target Indices After Sorting Array

// You are given a 0-indexed integer array nums and a target element target.

// A target index is an index i such that nums[i] == target.

// Return a list of the target indices of nums after sorting nums in
// non-decreasing order. If there are no target indices, return an empty list.
// The returned list must be sorted in increasing order.

// Example 1:

// Input: nums = [1,2,5,2,3], target = 2
// Output: [1,2]
// Explanation: After sorting, nums is [1,2,2,3,5].
// The indices where nums[i] == 2 are 1 and 2.

// Example 2:

// Input: nums = [1,2,5,2,3], target = 3
// Output: [3]
// Explanation: After sorting, nums is [1,2,2,3,5].
// The index where nums[i] == 3 is 3.

// Example 3:

// Input: nums = [1,2,5,2,3], target = 5
// Output: [4]
// Explanation: After sorting, nums is [1,2,2,3,5].
// The index where nums[i] == 5 is 4.

// Solution:

// Count number of elements less than the target.
// Count number of elements equal to the target.
// Use these to determine indices in sorted array.

#include <bits/stdc++.h>
using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
  int count_less = 0, count_equal = 0;

  for (auto num : nums) {
    if (num < target) {
      count_less += 1;
    }

    else if (num == target) {
      count_equal += 1;
    }
  }

  int target_index_start = count_less;
  int target_index_end = target_index_start + count_equal;

  vector<int> res;

  for (int i = target_index_start; i < target_index_end; i++) {
    res.push_back(i);
  }

  return res;
}
