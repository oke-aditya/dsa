// https://leetcode.com/problems/reduce-array-size-to-the-half/
// You are given an integer array arr.
// You can choose a set of integers and
// remove all the occurrences of these integers in the array.

// Return the minimum size of the set
// so that at least half of the integers of the array are removed.

// Example 1:

// Input: arr = [3,3,3,3,5,5,5,2,2,7]
// Output: 2

// Input: arr = [7,7,7,7,7,7]
// Output: 1

#include <bits/stdc++.h>

using namespace std;

template <typename... T>

void print_heap(priority_queue<T...> pq) {
  while (!pq.empty()) {
    cout << pq.top().first << " " << pq.top().second << " " << endl;
    pq.pop();
  }
}

int minSetSize(vector<int>& arr) {
  unordered_map<int, int> mp;

  for (auto ele : arr) {
    mp[ele] += 1;
  }

  priority_queue<pair<int, int>> maxh;

  for (auto itr = begin(mp); itr != end(mp); itr++) {
    maxh.push({itr->second, itr->first});
  }

  int n = arr.size();

  int count = 0;

  int n_eles = 0;

  // print_heap(maxh);

  while (!maxh.empty()) {
    pair<int, int> count_ele = maxh.top();
    count += count_ele.first;
    n_eles += 1;

    cout << count << " " << endl;

    if (count >= (n / 2)) {
      break;
    }

    maxh.pop();
  }

  return n_eles;
}
