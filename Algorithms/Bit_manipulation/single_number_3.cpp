// Given a non-empty array of integers, every element appears three times except
// for one, which appears exactly once. Find that single one.

// Input: [2,2,3,2]
// Output: 3

// https://leetcode.com/problems/single-number/solutions/1772139/c-explained-everything-w-why-xor-works-brute-force-to-optimized-step-by-step-dry-run/?envType=list&envId=503dr9s5

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
      nums[i + 1] = nums[i] ^ nums[i + 1];
    }

    return nums[n - 1];
  }
};