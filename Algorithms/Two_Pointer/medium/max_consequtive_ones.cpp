// Given a binary array, find the maximum number of consecutive 1s in this
// array.

// Input: [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive
// 1s.
//     The maximum number of consecutive 1s is 3.

#include <bits/stdc++.h>
using namespace std;

int max_conseq_ones(vector<int> v) {
  int count = 0;
  int max_count = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 1) {
      count += 1;
      max_count = max(max_count, count);
    } else {
      count = 0;
    }
  }
  return max_count;
}

int main(int argc, char const *argv[]) {
  vector<int> v = {1, 1, 0, 1, 1, 1};
  int res = max_conseq_ones(v);
  cout << res << endl;

  return 0;
}
