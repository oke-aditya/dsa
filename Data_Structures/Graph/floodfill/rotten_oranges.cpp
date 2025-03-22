// https://leetcode.com/problems/rotting-oranges/description/

// You are given an m x n grid where each cell can have one of three values:

//     0 representing an empty cell,
//     1 representing a fresh orange, or
//     2 representing a rotten orange.

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten
// orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a
// fresh orange. If this is impossible, return -1.

// solution:
// Figure out all the oranges that are rotting
// Add these to q
// then do a BFS

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};

  int orangesRotting(vector<vector<int>>& grid) {
    // we first need to know where rotting oranges are
    // then we can do multi source bfs
    // at every bfs we will change the grid to rotten
    // Eventually either the q is empty or the grid is fully rotten

    // need to retun no of steps. i.e. no of breadth in bfs
    // or return -1 if whole grid is not rotten

    queue<pair<int, int>> q;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
          visited[i][j] = 1;
        }
      }
    }

    int count = 0;
    // now we need to do bfs
    while (!q.empty()) {
      int l = q.size();
      while (l--) {
        pair<int, int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
          int new_x = x + dx[i];
          int new_y = y + dy[i];

          if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n &&
              grid[new_x][new_y] == 1 && !visited[new_x][new_y]) {
            visited[new_x][new_y] = 1;
            grid[new_x][new_y] = 2;
            q.push({new_x, new_y});
          }
        }
      }
      count += 1;
    }

    int fresh_oranges = 0;
    // check if anyone fresh oranges are left?
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // any orange left that is not rotten
        if (grid[i][j] == 1) {
          fresh_oranges += 1;
        }
      }
    }

    if (fresh_oranges > 0) {
      return -1;
    } else {
      // cap the count to 0, we can't have -ve rotten oranges.
      // count = -1 occurs when we had no rotten oranges
      return max(count - 1, 0);
    }
  }
};
