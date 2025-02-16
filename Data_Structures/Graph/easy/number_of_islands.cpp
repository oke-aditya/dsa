// // https://leetcode.com/problems/number-of-islands/description/

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

 
// Solution:

// Trick here is to find the number of connected components
// note diagonal does not form a connection
// Treat the matrix as graph and do a dfs
// Each cell is connected to 8 adjacent cells
// Use this info to do dfs

#include<bits/stdc++.h>
using namespace std;

bool is_safe(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &visited)
{
    int m = grid.size();
    int n = grid[0].size();

    return (i >= 0) && (i < m) && (j >= 0) && (j < n) && grid[i][j] == '1' && !visited[i][j]; 
}

void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j)
{
    // all combos except 0, 0

    // if we need to go 8 directions.
    // vector<int> rows = {-1, -1, -1, 0, 0, 1, 1, 1};
    // vector<int> cols = {-1, 0, 1, -1, 1, -1, 0, 1};

    // if we need only 4 directions
    vector<int> rows = {0, 0, 1, -1};
    vector<int> cols = {-1, 1, 0, 0};

    visited[i][j] = true;

    for(int z=0; z<4; z++)
    {
        int new_i = i + rows[z];
        int new_j = j + cols[z];

        if(is_safe(grid, new_i, new_j, visited))
        {
            dfs(grid, visited, new_i, new_j);
        }
    }
}


int numIslands(vector<vector<char>>& grid) 
{

    // m rows
    int m = grid.size();

    // n cols
    int n = grid[0].size();

    // visited of size m, n
    vector<vector<int>> visited(m, vector<int>(n));

    // simple iteration for count
    int count = 0;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] == '1' && !visited[i][j])
            {
                // do a dfs traversal
                dfs(grid, visited, i, j);

                // every dfs will cover an island
                count += 1;
            }
        }
    }

    return count;

}


