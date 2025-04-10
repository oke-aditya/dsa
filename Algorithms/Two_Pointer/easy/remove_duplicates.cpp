// Given a sorted array nums, remove the duplicates in-place such that each
// element appears only once and returns the new length.

// Do not allocate extra space for another array, you must do this by modifying
// the input array in-place with O(1) extra memory.

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4]
// Explanation: Your function should return length = 5, with the
// first five elements of nums being modified
// to 0, 1, 2, 3, and 4 respectively. It doesn't matter what values are set
// beyond the returned length.

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2]
// Explanation: Your function should return length = 2, with the first
// two elements of nums being 1 and 2 respectively.
// It doesn't matter what you leave beyond the returned length.

#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

// Another simple approach is to add numbers to set.
// Return all elements in set.

int remove_dup(vector<int> &v) {
  // v.erase(unique(v.begin(), v.end()), v.end());
  // return v;

  // Another way in O(n) is to shift the unique numbers to first.
  // Return the only till index of array where unique numbers are.

  if (v.size() == 0) {
    return 0;
  }

  int idx = 0;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] == v[i - 1]) {
      idx += 1;
    } else {
      v[i - idx] = v[i];
    }
  }
  return (v.size() - idx);
}

int main(int argc, char const *argv[]) {
  vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  auto res = remove_dup(v);
  cout << res;
  // print_v(res);

  return 0;
}
