// Given an array of integers arr[] and a number m, count the number of
// subarrays having XOR of their elements as m.

// Input : arr[] = {4, 2, 2, 6, 4}, m = 6
// Output : 4
// Explanation : The subarrays having XOR of
//               their elements as 6 are {4, 2},
//               {4, 2, 2, 6, 4}, {2, 2, 6},
//                and {6}

// Input : arr[] = {5, 6, 7, 8, 9}, m = 5
// Output : 2
// Explanation : The subarrays having XOR of
//               their elements as 5 are {5}
//               and {5, 6, 7, 8, 9}

#include <bits/stdc++.h>
using namespace std;

int xor_brute(vector<int> v, int m) {
  int count = 0;
  for (int i = 0; i < v.size(); i++) {
    int xor_sum = 0;
    for (int j = i; j < v.size(); j++) {
      xor_sum = xor_sum ^ v[j];
      // If it equal to m increase count
      if (xor_sum == m) {
        count += 1;
      }
    }
  }
  return count;
}

// This can also be done using sliding window.
// We need to find the count of such windows.
// Variable size sliding window qs.

int xor_hashed(vector<int> v, int m) {
  map<int, int> mp;
  int count = 0, xor_sum = 0;
  for (int i = 0; i < v.size(); i++) {
    xor_sum = xor_sum ^ v[i];

    if (xor_sum == m) {
      count += 1;
    }
    if (mp.find(xor_sum ^ m) != mp.end()) {
      count += mp[xor_sum ^ m];
    }
    mp[xor_sum] += 1;
  }
  return count;
}

int main(int argc, char const *argv[]) {
  vector<int> v = {4, 2, 2, 6, 4};
  int m = 6;

  auto res = xor_brute(v, m);
  cout << res << endl;

  auto res2 = xor_hashed(v, m);
  cout << res2 << endl;

  return 0;
}
