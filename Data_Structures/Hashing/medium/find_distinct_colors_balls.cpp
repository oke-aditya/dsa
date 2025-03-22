// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description

// You are given an integer limit and a 2D array queries of size n x 2.

// There are limit + 1 balls with distinct labels in the range [0, limit].
// Initially, all balls are uncolored. For every query in queries that is of the
// form [x, y], you mark ball x with the color y. After each query, you need to
// find the number of distinct colors among the balls. Return an array result of
// length n, where result[i] denotes the number of distinct colors after ith
// query. Note that when answering a query, lack of a color will not be
// considered as a color.

// Example 1:

// Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]
// Output: [1,2,2,3]

// Trick here is to use 2 hashmaps and concurrently update them
// First map maintains the index of ball, ball_map.
// Second map maintains colors of balls at indices.
// if we already have color and want to update, we assign it, decrease the
// colormap cleanup the colormap if color is 0. if the color is new add to the
// ballmap and add color to color map at end of every query the number of colors
// in colormap is the answer.

#include <bits/stdc++.h>
using namespace std;

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
  int n = queries.size();
  vector<int> result;
  unordered_map<int, int> color_map, ball_map;

  for (auto q : queries) {
    int ball_pos = q[0];
    int color = q[1];

    // ball map stores which ball has which color.

    // we do have a ball with this color
    if (ball_map.find(ball_pos) != ball_map.end()) {
      int prev_color = ball_map[ball_pos];
      color_map[prev_color] -= 1;

      // if this color is no longer being used remove it
      if (color_map[prev_color] == 0) {
        color_map.erase(prev_color);
      }
    }

    // whether we find ball or don't we should assign the color
    ball_map[ball_pos] = color;
    color_map[color] += 1;

    // after each query, number of items in color_map is the ans.
    result.push_back(color_map.size());
  }

  return result;
}
