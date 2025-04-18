// https://leetcode.com/problems/minimum-path-sum/description/

// Given a m x n grid filled with non-negative numbers,
// find a path from top left to bottom right, which minimizes the sum of all
// numbers along its path.

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp) {
  if (m < 0 || n < 0) {
    return 0;
  }

  if (dp[m][n] != -1) {
    return dp[m][n];
  }

  // base
  if (m == 0 && n == 0) {
    return grid[m][n];
  }

  if (m == 0) {
    dp[m][n] = grid[m][n] + helper(grid, m, n - 1, dp);
    return dp[m][n];
  }

  if (n == 0) {
    dp[m][n] = grid[m][n] + helper(grid, m - 1, n, dp);
    return dp[m][n];

  }

  else {
    dp[m][n] = grid[m][n] +
               min(helper(grid, m - 1, n, dp), helper(grid, m, n - 1, dp));
    return dp[m][n];
  }
}

int minPathSum(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  vector<vector<int>> dp(m, vector<int>(n, -1));

  int res = helper(grid, m - 1, n - 1, dp);
  return res;
}

int minPathSum2(vector<vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();

  vector<vector<int>> dp(m, vector<int>(n, 0));
  dp[0][0] = grid[0][0];

  // first row and column are direct access
  // take value itself
  for(int i=1; i<m; i++) {
      dp[i][0] = grid[i][0] + dp[i-1][0];
  }

  for(int j=1; j<n; j++) {
      dp[0][j] = grid[0][j] + dp[0][j-1];
  }

  // now in middle grid we have choice to move
  for(int i=1; i<m; i++) {
      for(int j=1; j<n; j++) {
          dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
      }
  }

  return dp[m-1][n-1];

}