// Given an array having both positive and negative integers.
// The task is to compute the length of the largest subarray with sum 0.

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.

#include <bits/stdc++.h>
using namespace std;

// Brute forece Solution
// Generate all subarrays and check sum

int max_subarray_brute(vector<int> v) {
  int i = 0, j = 0;
  int max_len = 0;
  for (i = 0; i < v.size(); i++) {
    int curr_sum = 0;
    for (j = i; j < v.size(); j++) {
      curr_sum += v[j];
      if (curr_sum == 0) {
        max_len = max(max_len, (j - i + 1));
      }
    }
  }
  return max_len;
}

// Optimized Solution 1.
// Sliding window solution, which can find subarray of any target size k.
// We need to find length of sliding window. Variable size sliding window q
// refer. Refer Maximum subarray with given sum k.

// Optimized solutino 2.
// Hashing to solve this problem.
// Create a map and store prefix sum
// In the map, store key as prefix sum and values as idex of array.
//

int max_subarray_hash(vector<int> v) {
  unordered_map<int, int> mp;
  int max_len = 0, sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
    // If sum is 0 then our max length will increase.
    if (sum == 0) {
      max_len += 1;
    } else {
      // We have found the current prefix sum in map.
      if (mp.find(sum) != mp.end()) {
        max_len = max(max_len, i - mp[sum]);
      } else {
        mp[sum] + i;
      }
    }
  }
  return max_len;
}

int main(int argc, char const *argv[]) {
  vector<int> v = {15, -2, 2, -8, 1, 7, 10, 23};

  auto res = max_subarray_brute(v);
  cout << res << endl;

  auto res2 = max_subarray_hash(v);
  cout << res2 << endl;

  return 0;
}
