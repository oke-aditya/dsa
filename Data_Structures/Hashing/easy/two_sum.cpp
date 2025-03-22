// Given an array of integers nums and an integer target, return indices of the
// two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.

// You can return the answer in any order.

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Input: nums = [3,3], target = 6
// Output: [0,1]

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

vector<int> two_sum_mp(vector<int> v, int target) {
  unordered_map<int, int> mp;
  int diff = 0;
  vector<int> res;

  for (int i = 0; i < v.size(); i++) {
    diff = target - v[i];
    if (mp.find(diff) == mp.end()) {
      mp[v[i]] = i;
    } else {
      res.push_back(mp[target - v[i]]);
      res.push_back(i);
    }
  }
  return res;
}

int main(int argc, char const *argv[]) {
  vector<int> v = {2, 7, 11, 15};
  int target = 9;
  auto res = two_sum_mp(v, target);
  print_v(res);

  return 0;
}
