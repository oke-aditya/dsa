// Given two strings s and t, check if s is a subsequence of t.

// A subsequence of a string is a new string that is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters.
// (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true

// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false

#include <bits/stdc++.h>

using namespace std;

bool isSubsequence(string s, string t) {
  int m = s.size();
  int n = t.size();

  int i = 0, j = 0;

  while (i < m && j < n) {
    if (s[i] == t[j]) {
      i += 1;
    }
    j += 1;
  }

  if (i == m) {
    return 1;
  } else {
    return 0;
  }
}
