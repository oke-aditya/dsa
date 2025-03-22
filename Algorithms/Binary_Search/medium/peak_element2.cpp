// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// Example 1:

// Input: arr = [0,1,0]
// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]
// Output: 1

// Input: arr = [0,5,7,10,3,2,1]
// Output: 3

// Input: arr = [0,5,7,10,11,12,3,2,1]
// Output: 5

// For a increasing and then decreasing array, find the maximum element

// CONTRAINT ARRAY SIZE > 3

#include <bits/stdc++.h>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
  int n = arr.size(), left = 0, right = n - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
      return mid;
    }

    else if (arr[mid] > arr[mid - 1]) {
      left = mid + 1;
    }

    else if (arr[mid] < arr[mid - 1]) {
      right = mid - 1;
    }
  }
}
