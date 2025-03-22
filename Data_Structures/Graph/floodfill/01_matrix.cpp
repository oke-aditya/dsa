// https://leetcode.com/problems/01-matrix/description/
// https://leetcode.com/problems/map-of-highest-peak/description/

// Given an m x n binary matrix mat, return the distance of the nearest 0 for
// each cell. The distance between two cells sharing a common edge is 1.

// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]

// solution

// this is very tricky,
// do not approach from 1s and try to do BFS
// approach from the 0s
// first mark every 0s as 0 length and others as -1
// Use the same visited array to do both marking and distance caculations
// Now do BFS from the 0s that were taken before
// Update the visited as + 1 from BFS and push to the queue
//

// For map of highest peak, the question is literally same
// Just that instead of 0s we need 1s

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> dx = {-1, 0, 0, 1};
  vector<int> dy = {0, -1, 1, 0};

  vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
    // length of bfs to 0 is needed from every 1?
    // we need to find all 1s first

    queue<pair<int, int>> q;

    int m = grid.size();
    int n = grid[0].size();

    // we will use this to mark visited and track the distance
    vector<vector<int>> visited(m, vector<int>(n, -1));

    // find 0 cells and mark their distance as 0

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          // 0 will have 0 distance from 0.
          visited[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    cout << q.size();

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

          if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n &&
              visited[new_x][new_y] == -1) {
            visited[new_x][new_y] = visited[x][y] + 1;
            q.push({new_x, new_y});
          }
        }
      }
    }
    return visited;
  }
};