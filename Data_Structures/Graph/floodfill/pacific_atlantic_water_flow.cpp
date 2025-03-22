// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

// There is an m x n rectangular island that borders both the Pacific Ocean and
// Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
// and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells.
// You are given an m x n integer matrix heights where heights[r][c]
// represents the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can
// flow to neighboring cells directly north, south, east, and west if the
// neighboring cell's height is less than or equal to the current cell's height.
// Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci]
// denotes that rain water can flow from cell (ri, ci) to both the Pacific and
// Atlantic oceans.

// Input: heights =
// [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]] Output:
// [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]] Explanation: The following cells
// can flow to the Pacific and Atlantic oceans, as shown below: [0,4]: [0,4] ->
// Pacific Ocean
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the
// Pacific and Atlantic oceans.

// solution

// the basic idea is for each cell we need distance from left / top side
// and bottom / right side
// But if we do this we will end up doing DFS on every cell which will take O(m
// * n) ^ 2 time Hence we play a trick here the first row & column is close to
// the pacific ocean, we use that to find if they can reach atlantic ocean the
// last column & row is closer to atlantic ocean, we use that to find if they
// can reach pacific ocean.' do 2 dfs, one on pacific ocean, one on atlantic
// ocean and then find intersection between the visited
//
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int> dx = {-1, 0, 0, 1};
  vector<int> dy = {0, -1, 1, 0};

  void dfs(int x, int y, vector<vector<int>> &grid,
           vector<vector<int>> &visited, int m, int n) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];

      if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n &&
          !visited[new_x][new_y] && grid[new_x][new_y] >= grid[x][y]) {
        dfs(new_x, new_y, grid, visited, m, n);
      }
    }
  }

 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> visited_pacific(m, vector<int>(n, 0));
    vector<vector<int>> visited_atlantic(m, vector<int>(n, 0));

    // visit pacific
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || j == 0) {
          dfs(i, j, grid, visited_pacific, m, n);
        }
      }
    }

    // visit atlantic
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == m - 1 || j == n - 1) {
          dfs(i, j, grid, visited_atlantic, m, n);
        }
      }
    }

    // intersec the two results
    vector<vector<int>> res;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (visited_pacific[i][j] && visited_atlantic[i][j]) {
          res.push_back({i, j});
        }
      }
    }
    return res;
  }
};
