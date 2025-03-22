// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/

// You are given a 0-indexed string blocks of length n, where blocks[i] is
// either 'W' or 'B', representing the color of the ith block. The characters
// 'W' and 'B' denote the colors white and black, respectively. You are also
// given an integer k, which is the desired number of consecutive black blocks.
// In one operation, you can recolor a white block such that it becomes a black
// block. Return the minimum number of operations needed such that there is at
// least one occurrence of k consecutive black blocks.

// Example 1:

// Input: blocks = "WBBWWBBWBW", k = 7
// Output: 3
// Explanation:
// One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and
// 4th blocks so that blocks = "BBBBBBBWBW". It can be shown that there is no
// way to achieve 7 consecutive black blocks in less than 3 operations.
// Therefore, we return 3.

// Example 2:

// Input: blocks = "WBWBBBW", k = 2
// Output: 0
// Explanation:
// No changes need to be made, since 2 consecutive black blocks already exist.
// Therefore, we return 0.

// Solution:
// sliding window of fixed size k
// keep track of Ws
// inimum number of ws is the answer.

#include <bits/stdc++.h>
using namespace std;

int minimumRecolors(string blocks, int k) {
  // let's make sliding window of size k
  // keep count of number of Bs
  // k - B is number of colors needed
  string W = "W";
  int count_w = 0;
  int i = 0, j = 0;
  for (j = 0; j < k; j++) {
    if (string{blocks[j]} == W) {
      count_w += 1;
    }
  }

  // no white balls, only black
  if (count_w == 0) {
    return 0;
  }

  int n = blocks.size();

  int min_recolors = count_w;
  int current_colors = count_w;

  for (j = k; j < n; j++) {
    if (string{blocks[j]} == W) {
      current_colors += 1;
    }
    if (string{blocks[i]} == W) {
      current_colors -= 1;
    }
    i += 1;

    min_recolors = min(min_recolors, current_colors);
  }

  return min_recolors;
}
