// // https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// There is an integer array nums sorted in ascending order (with distinct
// values).

// Prior to being passed to your function, nums is possibly rotated at an
// unknown pivot index k (1 <= k < nums.length) such that the resulting array is
// [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
// (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
// and become [4,5,6,7,0,1,2].

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Solution
// For each number we can check if we should go to the left/right by comparing
// it with target and with a[0]. Also, comparing target with a[0] tells us in
// which part (big or small numbers) the target is.

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
  int n = nums.size();
  int left = 0;
  int right = n - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    // we have found
    if (nums[mid] == target) {
      return mid;
    }

    if ((target >= nums[0] && (nums[mid] >= target || nums[mid] < nums[0])) ||
        (target < nums[0] && (nums[mid] < nums[0] && nums[mid] >= target))) {
      right = mid - 1;
    }

    else {
      left = mid + 1;
    }
  }

  return -1;
}
