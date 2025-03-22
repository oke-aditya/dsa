// Given an array and a positive integer k,
// find the first negative integer for each and /
// every window(contiguous subarray) of size k.

// Example:

// Input:
// 2
// 5
// -8 2 3 -6 10
// 2
// 8
// 12 -1 -7 8 -15 30 16 28
// 3

// Output:
// -8 0 -6 -6
// -1 -1 -7 -15 -15 0

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
}

vector<int> first_neg(vector<int> v, int k) {
  // Solve for first k elements.
  queue<int> q;
  vector<int> res;

  int n = v.size();

  for (int j = 0; j < k; j++) {
    if (v[j] < 0) {
      // We are pushing the index not the number.
      q.push(j);
    }
  }
  // No negative element found, print 0
  if (q.empty()) {
    res.push_back(0);
  } else {
    // We have a negative number, it will be at front of queue
    res.push_back(v[q.front()]);
  }

  // Now solve for remaining windows.
  int i = 0;
  for (int j = k; j < n; j++) {
    // Cleanup for ith element.
    // Empty queue till ith position is in queue.
    while ((!q.empty()) && q.front() < i + 1) {
      q.pop();
    }
    // Now do the same logic for jth element
    if (v[j] < 0) {
      q.push(j);
    }
    if (q.empty()) {
      res.push_back(0);
    } else {
      res.push_back(v[q.front()]);
    }
    i += 1;
  }
  return res;
}

int main(int argc, char const *argv[]) {
  vector<int> v{12, -1, -7, 8, -15, 30, 16, 28};
  int k = 3;
  auto res = first_neg(v, k);
  print_v(res);
  cout << endl;
  return 0;
}
