// https://leetcode.com/problems/contiguous-array/

// Given a binary array nums, return the maximum length of a contiguous subarray
// with an equal number of 0 and 1.

// Example 1:

// Input: nums = [0, 1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number
// of 0 and 1.

// Input: nums = [0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number
// of 0 and 1.

// Maintain a deficit array
// if the value is 1, add 1, value is 0 add -1.
// now this deficit array captures where we have equal 0s and 1s.
// If we find 0 in deficit array, we have equal number of 0s and 1s.
// the index would help us in answering max length.
// the problem is, what is deficit array has 2 equal numbers.
// these too are valid solution
// we need to capture them, hence use a map.
// store the deficit index as we process.
// check if we have that deficit again.
// if we do have, then we have an answer.

#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
  int n = nums.size();
  // vector<int> deficit_arr(n);

  int deficit = 0;
  int result = 0;

  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) {
      deficit -= 1;
    } else {
      deficit += 1;
    }

    if (deficit == 0) {
      result = max(result, i + 1);
    }

    if (mp.find(deficit) != mp.end()) {
      result = max(result, i - mp[deficit]);
    }

    else {
      mp[deficit] = i;
    }
  }

  return result;
}
