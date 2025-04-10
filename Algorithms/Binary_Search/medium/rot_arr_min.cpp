// Find the Rotation Count in RIGHT Rotated Sorted array
// Consider an array of distinct numbers sorted in increasing order.
// The array has been rotated (clockwise) k number of times. Given such an
// array, find the value of k.

// Also

// Find minimum in rotated sorted array.
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// This gives the index of minimum element. We can use this to solve

// Examples:

// Input : arr[] = {15, 18, 2, 3, 6, 12}
// Output: 2
// Explanation : Initial array must be {2, 3,
// 6, 12, 15, 18}. We get the given array after
// rotating the initial array twice.

// Input : arr[] = {7, 9, 11, 12, 5}
// Output: 4

// Input: arr[] = {7, 9, 11, 12, 15};
// Output: 0

// Solution: - We have to find the location of minimum value in the array.
// Keep it simple.
// Search right if we know that there are smaller numbers than mid
// else search left
// index of minimum number is the right rotation count.

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
  int left = 0;
  int n = nums.size();
  int right = n - 1;
  int ans = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    // middle number is smaller than last. so this could one of the lowest
    // numbers
    if (nums[mid] <= nums[n - 1]) {
      ans = nums[mid];
      right = mid - 1;
    }

    // the middle element is greater than last. so there are smaller numbers on
    // right
    else {
      left = mid + 1;
    }
  }

  return ans;
}

// alternate long cut

int findMin2(vector<int>& nums) {
  int left = 0;
  int n = nums.size();
  int right = n - 1, ans = 0;

  if(n == 1) {
      return nums[0];
  }

  while(left <= right) {
      int mid = left + (right - left) / 2;

      if(mid == 0) {
          if(nums[mid+1] > nums[mid]) {
              return nums[mid];
          }
          else {
              return nums[mid+1];
          }
      }

      else if(mid == (n - 1)) {
          if(nums[mid-1] > nums[mid]) {
              return nums[mid];
          }
          else {
              return nums[mid-1];
          }
      }

      // smaller on both sides.
      else if((nums[mid - 1] > nums[mid]) && nums[mid + 1] > nums[mid]) {
          return nums[mid];
      }

      // there are smaller number to the right and no smaller numbers on left
      // move right
      else if (nums[n-1] < nums[mid] && nums[mid] > nums[0]) {
          left = mid + 1;
      }

      else {
          right = mid - 1;
      }
  }

  return ans;
}

int main(int argc, char const* argv[]) {
  vector<int> arr = {15, 18, 2, 3, 6, 12};
  int n = sizeof(arr) / sizeof(arr[0]);
  int res = findMin(arr);
  cout << res << endl;
  return 0;
}
