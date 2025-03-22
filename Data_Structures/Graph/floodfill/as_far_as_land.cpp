// https://leetcode.com/problems/as-far-from-land-as-possible/description/

// Given an n x n grid containing only values 0 and 1, where 0 represents water
// and 1 represents land, find a water cell such that its distance to the
// nearest land cell is maximized, and return the distance. If no land or water
// exists in the grid, return -1. The distance used in this problem is the
// Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is
// |x0 - x1| + |y0 - y1|.

// solution:
// Idea is very similar to 0-1 matrix.
// keep track of all 1s, distance on them is 0.
// Here too we abuse visited to do both the jobs, distance as well as the
// visited tracking For all other nodes adjacent to 1, do a BFS visited on every
// new neighbor will be 1 + visited of previous x and y the maximum value is the
// farthest value in the island

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, 1, -1};

  int maxDistance(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // intentionally marking with -1
    vector<vector<int>> visited(m, vector<int>(n, -1));

    // mark all 1s with 0 distance
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          q.push({i, j});
          visited[i][j] = 0;
        }
      }
    }
    cout << q.size();

    // grid full of 1s or 0s?
    if (q.size() == (n * m) || q.size() == 0) {
      return -1;
    }

    while (!q.empty()) {
      int l = q.size();
      while (l--) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;

        for (int i = 0; i < 4; i++) {
          int new_x = x + dx[i];
          int new_y = y + dy[i];

          // note the use of visited here, we had initialized with -1
          // here we care only on 0s, 1s were already taken care of
          if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n &&
              visited[new_x][new_y] == -1 && grid[new_x][new_y] == 0) {
            // this is the trick, 1 + previous
            visited[new_x][new_y] = 1 + visited[x][y];
            q.push({new_x, new_y});
          }
        }
      }
    }

    // just find max in the matrix
    int max_dist = -1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        max_dist = max(max_dist, visited[i][j]);
      }
    }

    return max_dist;
  }
};
