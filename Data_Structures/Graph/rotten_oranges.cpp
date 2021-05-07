// https://leetcode.com/problems/rotting-oranges/

// You are given an m x n grid where each cell can have one of three values:

//     0 representing an empty cell,
//     1 representing a fresh orange, or
//     2 representing a rotten orange.

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

// The trick is to start bfs from all initial rotten oranges simultaneously to get minimum time,
// this way any oranges that can get rotten du
// to more than 1 initially rotten oranges will be covered by the nearest one.

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    // Since we need to check for 4 directions
    vector<int> dir = {-1, 0, 1, 0, -1};

    int m = grid.size();
    int n = grid[0].size();

    // queue for BFS
    queue<pair<int, int>> q;

    int fresh = 0; // Keep track of fresh oranges left.

    // Add all the rotten oranges to queue to perform bfs
    // Also count all the fresh oranges

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                fresh += 1;
            }
        }
    }

    //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
    int ans = -1;

    while (!q.empty())
    {
        // number of rotten oranges.
        int sz = q.size();

        // For all the rotten oranges.
        while (sz--)
        {
            // Get the location
            pair<int, int> p = q.front();
            q.pop();

            // search in all 4 directions
            for (int i = 0; i < 4; i++)
            {
                int r = p.first + dir[i];
                int c = p.second + dir[i + 1];
                
                // If within the limits and is fresh
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                {
                    // Mark this as rotten
                    grid[r][c] = 2;
                    // Now this is rotten so queue will get it.
                    q.push({r, c});
                    // fresh orange is rotten
                    fresh -= 1;
                }
            }
        }
        // This has rotten.
        ans += 1;
    }

    // All are not rotten
    if (fresh > 0)
    {
        return -1;
    }

    // No rotten oranges.
    if (ans == -1)
    {
        return 0;
    }

    return ans;

}
