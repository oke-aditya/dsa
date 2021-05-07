// https://leetcode.com/problems/number-of-islands/

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and
// '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent
// lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3


// Iterate through each of the cell and if it is an island, do dfs to mark all adjacent islands, then increase the counter by 1.

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();

    // If we are outside
    if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0')
    {
        return;
    }

    grid[i][j] = '0';

    dfs(grid, i-1, j);
    dfs(grid, i+1, j);
    dfs(grid, i, j-1);
    dfs(grid, i, j+1);

}


int numIslands(vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] == '1')
            {
                count += 1;
                dfs(grid, i, j);
            }
        }
    }
    return count;

}

int main(int argc, char const *argv[])
{
    
    return 0;
}


