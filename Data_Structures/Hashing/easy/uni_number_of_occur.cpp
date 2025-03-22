// https://leetcode.com/problems/unique-number-of-occurrences/
// Unique Number of Occurrences

// Given an array of integers arr, write a function that
// returns true if and only if the number of occurrences of each value in the
// array is unique.

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two
// values have the same number of occurrences.

// Example 2:

// Input: arr = [1,2]
// Output: false

// Example 3:

// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
// Output: true

// Solution: -
// Create a map1 to store how many times the element occured.
// Create a map2 to store how many times did the elements in map1 occured.
// If any count > 1 in second map, return false.
// Else return true.

#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr) {
  unordered_map<int, int> mp;

  for (int ele : arr) {
    mp[ele]++;
  }

  unordered_map<int, int> mp2;

  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    mp2[itr->second]++;
  }

  for (auto itr2 = mp2.begin(); itr2 != mp2.end(); itr2++) {
    if (itr2->second > 1) {
      return false;
    }
  }

  return true;
}
