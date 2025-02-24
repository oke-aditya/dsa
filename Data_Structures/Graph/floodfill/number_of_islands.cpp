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

class Solution 
{
    public:
    
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};
    
        // pass visited by reference (mainpulations)!! and grid too (for efficiency) !!
        void dfs(int x, int y, vector<vector<int>> &visited, vector<vector<char>> &grid, int m, int n)
        {
            visited[x][y] = 1;
            for(int i=0; i<4; i++)
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
    
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y] && grid[new_x][new_y] == '1')
                {
                    dfs(new_x, new_y, visited, grid, m, n);
                }
            }
        }
    
        int numIslands(vector<vector<char>>& grid) 
        {
            // again stratightforawrd flood fill.
            // aim here is to to dfs from every cell
            // imagine we have disconnected graphs
            // each cell needs to have dfs / bfs
    
            int m = grid.size();
            int n = grid[0].size();
    
            // we need to keep track of visited
            // because we will do dfs from multiple sources
    
            vector<vector<int>> visited(m, vector<int>(n, 0));
    
            // every bfs / dfs will give us an island
            int number_islands = 0;
    
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(grid[i][j] == '1' && !visited[i][j])
                    {
                        dfs(i, j, visited, grid, m, n);
                        number_islands += 1;
                    }
                }
            }
    
            return number_islands;
    
        }
};
