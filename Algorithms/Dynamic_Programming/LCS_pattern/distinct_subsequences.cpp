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

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag

// Solution:
// The question is how many times t appears in s.
// For each character in t, if it is same, we can take it or not take it.
// Otherwise, we will ignore the character in s
// 
// 

#include <bits/stdc++.h>
using namespace std;

int helper(string &s, int m, string &t, int n, vector<vector<int>> &dp) {

  // the condition order matters, due to initial state set.
  // when m == 0 & n == 0 return 1
  // no of subseq in "" for ""
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



int num_dist_bu(string s, int m, string t, int n) {

  // 2 states, s, and t
  vector<vector<double>> dp(m+1, vector<double>(n + 1, 0));

  for(int i=0; i<m; i++) {
      for(int j=0; j<n; j++) {
          // first string is empty, 
          // we get 0 subseq
          if(i == 0) {
              dp[i][j] = 0;
          }

          // if second is empty,
          // we will always have 1 occ
          if(j == 0) {
              dp[i][j] = 1;
          }
      }
  }
  // empty string with empty
  dp[0][0] = 1;


  // for other cases

  for(int i=1; i<=m; i++) {
      for(int j=1; j<=n; j++) {
          if(s[i-1] == t[j-1]) {
              // pick + not pick
              dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
          }
          else {
              dp[i][j] = dp[i-1][j];
          }
      }
  }

  return dp[m][n];
}

int numDistinct2(string s, string t) {
  int m = s.size();
  int n = t.size();

  return num_dist_bu(s, m , t, n);
}