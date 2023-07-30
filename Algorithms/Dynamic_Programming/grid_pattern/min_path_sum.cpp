// https://leetcode.com/problems/minimum-path-sum/description/

// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp)
{
    if(m < 0 || n < 0)
    {
        return 0;
    }

    if(dp[m][n] != -1)
    {
        return dp[m][n];
    }

    // base
    if(m == 0 && n == 0)
    {
        return grid[m][n];
    }

    if(m == 0)
    {
        dp[m][n] = grid[m][n] + helper(grid, m, n-1, dp);
        return dp[m][n];
    }

    if(n == 0)
    {
        dp[m][n] = grid[m][n] + helper(grid, m-1, n, dp);
        return dp[m][n];

    }

    else
    {
        dp[m][n] = grid[m][n] + min(helper(grid, m-1, n, dp), helper(grid, m, n-1, dp));
        return dp[m][n];
    }

}

int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size();
    
    vector<vector<int>> dp(m, vector<int> (n, -1));

    int res = helper(grid, m-1, n-1, dp);
    return res;
}

int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size();
    
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

    // int res = helper(grid, m-1, n-1, dp);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }

            else if(i == 0)
            {
                dp[i][j] = grid[i][j] + dp[i][j-1];
            }

            else if(j == 0)
            {
                dp[i][j] = grid[i][j] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }

            cout<<i<<" "<<j<<endl;
            cout<<dp[i][j]<<endl;

        }
    }

    return dp[m-1][n-1];
}