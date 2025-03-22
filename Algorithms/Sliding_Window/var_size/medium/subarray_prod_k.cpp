// https://leetcode.com/problems/subarray-product-less-than-k/

// Given an array of integers nums and an integer k, return the number of
// contiguous subarrays where the product of all the elements in the subarray is
// strictly less than k.

// Example 1:

// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly
// less than k.

// Solution:
// Trick to counting these subarrays are checking the length of the window.
// We can slide the window if the cur_prod >= k.
//

#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
  // note that given array does not have 0s in nums
  int count = 0;

  int i = 0, j = 0;

  int n = nums.size();

  int cur_prod = 1;
  for (int j = 0; j < n; j++) {
    cur_prod *= nums[j];

    while (cur_prod >= k && i <= j) {
      cur_prod = cur_prod / nums[i];
      i += 1;
    }

    // All subarrays ending at `right` and starting from any index between
    // `left` and `right`
    // are valid subarrays, so we add (right - left + 1) to the result
    count += (j - i) + 1;
  }

  return count;
}
