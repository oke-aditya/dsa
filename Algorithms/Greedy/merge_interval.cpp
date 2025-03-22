
// Given an array of intervals where intervals[i] = [starti, endi]
// merge all overlapping intervals,
// and return an array of the non-overlapping intervals that cover all the
// intervals in the input.

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

// Solution:
// Sort the intervals.
// Now for every interval compare interval[1] with next interval[0]
// If it is true, then merge the intervals.
// Else Push the temporary answer to result.

#include <bits/stdc++.h>
using namespace std;

void print_vv(vector<vector<int>> vv) {
  cout << "[";
  for (auto v : vv) {
    cout << "[" << v[0] << " " << v[1] << "]";
  }
  cout << "]";
  cout << endl;
}

vector<vector<int>> merge_interv(vector<vector<int>> &intervals) {
  vector<vector<int>> res;
  if (intervals.size() == 0) {
    return res;
  }

  // Sort the intervals
  sort(intervals.begin(), intervals.end());

  vector<int> temp_interval = intervals[0];

  for (auto intv : intervals) {
    if (temp_interval[1] >= intv[0]) {
      temp_interval[1] = max(intv[1], temp_interval[1]);
    } else {
      res.push_back(temp_interval);
      temp_interval = intv;
    }
  }
  res.push_back(temp_interval);
  return res;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

  auto res = merge_interv(v);
  print_vv(res);

  return 0;
}
