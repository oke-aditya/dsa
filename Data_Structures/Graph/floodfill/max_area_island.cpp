// https://leetcode.com/problems/max-area-of-island/

// You are given an m x n binary matrix grid. An island is a group of 1's
// (representing land) connected 4-directionally (horizontal or vertical.) You
// may assume all four edges of the grid are surrounded by water.
//
// The area of an island is the number of cells with a value 1 in the island.
//
// Return the maximum area of an island in grid. If there is no island, return
// 0.

// Input: grid =
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected
// 4-directionally.

// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0

// Solution:
// sum of visited will give area of current dfs coverage
//
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> dx = {-1, 0, 0, 1};
  vector<int> dy = {0, 1, -1, 0};

  // same dfs, just twist is to add every cell as area
  void dfs(int x, int y, vector<vector<int>> &grid,
           vector<vector<int>> &visited, int m, int n, int &area) {
    area += 1;
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];

      if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n &&
          !visited[new_x][new_y] && grid[new_x][new_y] == 1) {
        dfs(new_x, new_y, grid, visited, m, n, area);
      }
    }
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int max_area = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          // reset the area
          int curr_area = 0;
          // pass area as reference and update it
          dfs(i, j, grid, visited, m, n, curr_area);
          max_area = max(max_area, curr_area);
        }
      }
    }
    return max_area;
  }
};

// bfs solution

class Solution2 {
public:

    vector<int> dx = {-1, 1, 0, 0 };
    vector<int> dy = {0, 0, 1, -1};

    // bfs solution
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        // append all 1s to a queue?
        queue<pair<int, int>> q;
        int max_area = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    int area = 1;

                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        // bfs all 4 directions
                        for(int i=0; i<4; i++) {
                            int new_x = x + dx[i];
                            int new_y = y + dy[i];
                            if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] && !visited[new_x][new_y]) {
                                area += 1;
                                visited[new_x][new_y] = 1;
                                q.push({new_x, new_y});
                            }
                        }
                    }
                    max_area = max(max_area, area);
                }
            }
        }

        return max_area;

    }
};

