// https://leetcode.com/problems/unique-paths-ii/

// Unique Path 2

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in
// the diagram below).

// The robot can only move either down or right at any point in time.

// The robot is trying to reach the bottom-right corner of the grid (marked
// 'Finish' in the diagram below).

// Now consider if some obstacles are added to the grids. How many unique paths
// would there be?

// An obstacle and space is marked as 1 and 0 respectively in the grid.

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Solution: -
// Do not try memoizing it's slightly hard. Directly write bu solution.
// Again this is modification of path1 problem.
// We need to perform additional checks.

#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &grid, int m, int n, vector<vector<int>> dp) {
  if (m < 0 || n < 0) {
    return 0;
  }

  if (grid[m][n] == 1 && m >= 0 && n >= 0) {
    return 0;
  }

  if (m == 0 && n == 0) {
    return 1;
  }

  if (dp[m][n] != -1) {
    return dp[m][n];
  }

  else {
    int left = helper(grid, m - 1, n, dp);
    int right = helper(grid, m, n - 1, dp);
    dp[m][n] = left + right;
    return dp[m][n];
  }
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();

  vector<vector<int>> dp(m, vector<int>(n, -1));

  int res = helper(obstacleGrid, m - 1, n - 1, dp);

  return res % (2 * 1000000000);
}

// iterative dp.

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();

  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (obstacleGrid[i][j] == 1) {
        dp[i][j] = 0;
        // continue;
      } else if (i == 0 && j == 0) {
        dp[i][j] = 1;
      } else {
        int up = 0, left = 0;
        if (i > 0) {
          up = dp[i - 1][j];
        }
        if (j > 0) {
          left = dp[i][j - 1];
        }

        dp[i][j] = up + left;
      }
    }
  }
  return dp[m - 1][n - 1] % (2 * 1000000000);
}
