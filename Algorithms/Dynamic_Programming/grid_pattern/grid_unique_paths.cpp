#include <bits/stdc++.h>
using namespace std;

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

// Input: m = 3, n = 7
// Output: 28

// Input: m = 3, n = 2
// Output: 3

// Input: m = 3, n = 3
// Output: 6

int solve_grid(int i, int j, int m, int n)
{
    // If we go out or are at the perfect square
    if (i >= n || j >= m)
    {
        return 0;
    }
    // Just one square behind some where.
    if (i == (n - 1) || j == (m - 1))
    {
        return 1;
    }
    else
    {
        // Move either right or down.
        return solve_grid(i + 1, j, m, n) + solve_grid(i, j + 1, m, n);
    }
}

int grid_paths_rec(int m, int n)
{
    // Iniitial location.
    int i = 0, j = 0;
    int res = solve_grid(i, j, m, n);
    return res;
}

int dp[1000][1000];

int solve_grid_mem(int i, int j, int m, int n)
{
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    else
    {
        // If we go out or are at the perfect square
        if (i >= n || j >= m)
        {
            return 0;
        }
        // Just one square behind some where.
        if (i == (n - 1) || j == (m - 1))
        {
            return 1;
        }
        else
        {
            // Move either right or down.
            return solve_grid_mem(i + 1, j, m, n) + solve_grid_mem(i, j + 1, m, n);
        }
    }
}

int grid_paths_mem(int m, int n)
{
    int i = 0, j = 0;
    int res = solve_grid_mem(i, j, m, n);
    return res;
}

int grid_paths_bu(int m, int n)
{
    int i=0, j=0;
    int dp[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];    
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    int m = 3, n = 7;
    memset(dp, -1, sizeof(dp));
    cout << grid_paths_rec(m, n) << endl;
    cout << grid_paths_mem(m, n) << endl;

    memset(dp, -1, sizeof(dp));
    cout << grid_paths_bu(m, n)<<endl;

    int m2 = 3, n2 = 2;
    memset(dp, -1, sizeof(dp));
    cout << grid_paths_rec(m2, n2) << endl;
    cout << grid_paths_mem(m2, n2) << endl;

    cout << grid_paths_bu(m2, n2)<<endl;

    return (0);
}
