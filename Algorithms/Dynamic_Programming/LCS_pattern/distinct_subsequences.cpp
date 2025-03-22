// https://leetcode.com/problems/distinct-subsequences/
// Given two strings s and t, return the number of distinct
// subsequences
// of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed
// integer.

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit

#include <bits/stdc++.h>
using namespace std;

int helper(string &s, int m, string &t, int n, vector<vector<int>> &dp) {
  if (n == 0) {
    return 1;
  }

  if (m == 0) {
    return 0;
  }

  if (dp[m][n] != -1) {
    return dp[m][n];
  }

  else {
    if (s[m - 1] == t[n - 1]) {
      dp[m][n] = helper(s, m - 1, t, n - 1, dp) + helper(s, m - 1, t, n, dp);
    } else {
      dp[m][n] = helper(s, m - 1, t, n, dp);
    }
  }

  return dp[m][n];
}

int numDistinct(string s, string t) {
  int m = s.size();
  int n = t.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  // memset(dp, sizeof(dp), -1)

  int res = helper(s, m, t, n, dp);
  return res;
}