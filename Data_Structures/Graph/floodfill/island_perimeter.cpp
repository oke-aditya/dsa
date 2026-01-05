// https://leetcode.com/problems/island-perimeter/

// You are given row x col grid representing a map where grid[i][j] = 1 
// represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). 
// The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int perimeter = 0;

    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &visited, int m, int n) {
        
        visited[x][y] = 1;

        for(int i=0; i<4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            // If out of bounds or water, add to perimeter
            if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || grid[new_x][new_y] == 0) {
                perimeter += 1;
            }
            // If valid land cell and not visited, continue DFS
            else if(grid[new_x][new_y] && !visited[new_x][new_y]) {
                dfs(new_x, new_y, grid, visited, m, n);
            }
        }

    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    dfs(i, j, grid, visited, m, n);
                }
            }
        }

        return perimeter;
    }
};


