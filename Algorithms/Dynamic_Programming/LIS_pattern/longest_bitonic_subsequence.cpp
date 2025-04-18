// https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
// Longest Bitonic Subsequence

// Given an array arr[0 … n-1] containing n positive integers,
// a subsequence of arr[] is called Bitonic if it is first increasing,
// then decreasing.
// Write a function that takes an array as argument
// and returns the length of the longest bitonic subsequence.

// Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
// Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

// Input arr[] = {12, 11, 40, 5, 3, 1}
// Output: 5 (A Longest Bitonic Subsequence of length 5 is 12, 11, 5, 3, 1)

// Input arr[] = {80, 60, 30, 40, 20, 10}
// Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)

#include <bits/stdc++.h>

using namespace std;

int LongestBitonicSequence(int n, vector<int> &nums) {
  // code here
  
  // find LDS and reverse LDS
  // int n = nums.size();
  vector<int> dp1(n, 1);
  vector<int> dp2(n, 1);
  
  // LDS
  for(int i = n-1; i >= 0; i--) {
      for(int j = n-1; j > i; j--) {
          // the one on the right is smaller
          // so update dp2[i]
          if(nums[i] > nums[j]) {
              dp1[i] = max(dp1[i], 1 + dp1[j]);
          }
      }
  }
  
  // Not LDS, We just compute LDS in Reverse Direction
  // we cannot compute LDS here, we need opposite direction LIS
  for(int i = 0; i < n; i++) {
      for(int j = 0; j < i; j++) {
          // Reverse condition
          if(nums[i] > nums[j]) {
              dp2[i] = max(dp2[i], 1 + dp2[j]);
          }
      }
  }
  
  
  // Find the maximum length of bitonic subsequence
  int maxLength = 0;
  for(int i = 0; i < n; i++) {
      if(dp1[i] > 1 && dp2[i] >> 1) {
          // Bitonic subsequence length is LIS[i] + LDS[i] - 1 (because nums[i] is counted twice)
          maxLength = max(maxLength, dp1[i] + dp2[i] - 1);
      }
  }

  return maxLength;
}

