// https://leetcode.com/problems/count-number-of-bad-pairs/?

// You are given a 0-indexed integer array nums. A pair of indices (i, j) is a
// bad pair if i < j and j - i != nums[j] - nums[i].

// Return the total number of bad pairs in nums.

// Example 1:

// Input: nums = [4,1,3,3]
// Output: 5
// Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
// The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
// The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
// The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
// The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
// There are a total of 5 bad pairs, so we return 5.

#include <bits/stdc++.h>
using namespace std;

// brute force O(n2): TLE
// simply do as stated

long long countBadPairs(vector<int>& nums) {
  long long count = 0;
  int n = nums.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((j - i) != (nums[j] - nums[i])) {
        count += 1;
      }
    }
  }
  return count;
}

// Optimized O(n) approach is to keep num[i] - i in a hashmap
// then count the number of pairs

long long countBadPairs2(vector<int>& nums) {
  long long bad_pairs = 0;
  int n = nums.size();

  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++) {
    int diff = i - nums[i];

    // / Count of previous positions with same difference
    int good_pairs = mp[diff];

    // Total possible pairs minus good pairs = bad pairs
    bad_pairs += i - good_pairs;

    // Update count of positions with this difference
    mp[diff] = good_pairs + 1;
  }

  return bad_pairs;
}
