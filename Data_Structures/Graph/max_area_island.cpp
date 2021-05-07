// https://leetcode.com/problems/max-area-of-island/

// You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
// connected 4-directionally (horizontal or vertical.)
// You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

// Solution: -

// The solution is to search each island. Remember marking grid[r][c] = 2 as visited.
// Either use DFS / BFS

#include <bits/stdc++.h>
using namespace std;

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                ans = max(ans, dfs(grid, i, j));
            }
        }
    }
    return ans;
}

// Eihter use DFS

int dfs(vector<vector<int>> &grid, int row, int col)
{
    int m = grid.size(), n = grid[0].size(), area = 1;

    // Marking it as visited.
    grid[row][col] = 2;

    // directions to navigate
    vector<int> dir({-1, 0, 1, 0, -1});

    for (int i = 0; i < 4; i++)
    {
        int r = row + dir[i], c = col + dir[i + 1];
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
        {
            area += dfs(grid, r, c);
        }
    }
    return area;
}

int bfs(vector<vector<int>> &grid, int row, int col)
{
    int m = grid.size(), n = grid[0].size(), area = 1;

    queue<pair<int, int>> q;

    q.push({row, col});

    // Marking it as visited.
    grid[row][col] = 2;

    // directions to navigate
    vector<int> dir{{-1, 0, 1, 0, -1}};

    while (!q.empty())
    {
        int z = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = z + dir[i], c = x + dir[i + 1];
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
            {
                grid[r][c] = 2;
                area++;
                q.push({r, c});
            }
        }
    }
    return area;
}
