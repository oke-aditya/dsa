// https://leetcode.com/problems/unique-paths/
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in
// the diagram below).

// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid (marked
// 'Finish' in the diagram below).

// How many possible unique paths are there?

// Input: m = 3, n = 7
// Output: 28

// Input: m = 3, n = 2
// Output: 3

// Input: m = 3, n = 3
// Output: 6

#include <bits/stdc++.h>
using namespace std;

int helper(int m, int n, vector<vector<int>> &dp) {
  if (m == 0 && n == 0) {
    return 1;
  }

  if (m < 0 || n < 0) {
    return 0;
  }

  if (dp[m][n] != -1) {
    return dp[m][n];
  }

  int up = helper(m - 1, n, dp);
  int left = helper(m, n - 1, dp);

  dp[m][n] = up + left;
  return dp[m][n];
}

int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  return helper(m - 1, n - 1, dp);
}

int grid_paths_bu(int m, int n) {
  int i = 0, j = 0;
  int dp[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }
  return dp[m - 1][n - 1];
}
