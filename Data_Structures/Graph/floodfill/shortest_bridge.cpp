// https://leetcode.com/problems/shortest-bridge/description/

// You are given an n x n binary matrix grid where 1 represents land and 0
// represents water. An island is a 4-directionally connected group of 1's not
// connected to any other 1's. There are exactly two islands in grid. You may
// change 0's to 1's to connect the two islands to form one island. Return the
// smallest number of 0's you must flip to connect the two islands.

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 1

// Example 2:

// Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2

// Example 3:

// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1

// Solution
// Trick here is to do a dfs and a bfs
// Flood fill DFS will populate the visited array with first island
// from this first island, we can do bfs to reach the 2nd one
// length of bfs would be length of shortest bridge

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, 1, -1, 0};

  void dfs(int x, int y, vector<vector<int>>& grid,
           vector<vector<int>>& visited, int m, int n,
           queue<pair<int, int>>& q) {
    visited[x][y] = 1;
    q.push({x, y});
    for (int i = 0; i < 4; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
        if (!visited[new_x][new_y] && grid[new_x][new_y] == 1) {
          dfs(new_x, new_y, grid, visited, m, n, q);
        }
      }
    }
  }

  int shortestBridge(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();

    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    bool flag = false;

    // Step 1: Use DFS to find the first island and add its boundary cells to
    // the queue
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && !flag) {
          dfs(i, j, grid, visited, m, n, q);
          flag = true;
          break;
        }
      }
      if (flag) break;
    }

    // Step 2: Use BFS to find the shortest bridge to the second island
    int min_dist = 0;
    while (!q.empty()) {
      int len = q.size();
      min_dist += 1;  // Each level of BFS represents one step away from the
                      // first island
      while (len--) {
        pair<int, int> poi = q.front();
        q.pop();
        visited[poi.first][poi.second] = 1;

        for (int i = 0; i < 4; i++) {
          int xd = poi.first + dx[i];
          int yd = poi.second + dy[i];
          if (xd >= 0 && yd >= 0 && xd < m && yd < n) {
            if (!visited[xd][yd]) {
              if (grid[xd][yd] == 1) {
                return min_dist - 1;  // If we encounter the second island,
                                      // return the distance
              } else if (grid[xd][yd] == 0) {
                visited[xd][yd] = 1;  // Mark as visited and continue BFS
                q.push({xd, yd});
              }
            }
          }
        }
      }
    }

    return -1;  // In case there is no path (although it's guaranteed to find
                // one in this problem)
  }
};
