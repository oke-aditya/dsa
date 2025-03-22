// https://leetcode.com/problems/single-element-in-a-sorted-array/

// You are given a sorted array consisting of only integers where
// every element appears exactly twice,
// except for one element which appears exactly once.
// Find this single element that appears only once.

// Follow up: Your solution should run in O(log n) time and O(1) space.

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

// most basic approach would be unordered map and find out.
// we can do better with binary search

// also a genius approach is to XOR and check
// https://leetcode.com/problems/single-element-in-a-sorted-array/solutions/100732/short-compare-nums-i-with-nums-i-1/
// num[mid] == num[mid ^ 1]
// odd xor 1 = odd-1
// even xor 1 = even+1

#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
  int left = 0;
  int n = nums.size();
  int right = n - 1;

  int ans = -1;

  if (n == 1) {
    return nums[0];
  }

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (mid == 0) {
      if (nums[mid + 1] != nums[mid]) {
        return nums[mid];
      }
    }

    else if (mid == n - 1) {
      if (nums[mid - 1] != nums[mid]) {
        return nums[mid];
      }
    }

    // even index / odd position.
    // it's not same in either direction
    else if (mid % 2 == 0 && nums[mid - 1] != nums[mid] &&
             nums[mid + 1] != nums[mid]) {
      return nums[mid];
    }

    // even index / odd position. it is the first occurence
    // no faults here
    else if (mid % 2 == 0 && nums[mid + 1] == nums[mid]) {
      left = mid + 1;
    }

    // odd index / even position
    // this is the 2nd occurence.
    // then there are no issues here, move right
    else if (mid % 2 == 1 && nums[mid - 1] == nums[mid]) {
      left = mid + 1;
    }

    else {
      right = mid - 1;
    }
  }
  return ans;
}
