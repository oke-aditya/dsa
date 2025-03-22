// Given an array nums of n integers, are there elements a, b, c in nums such
// that a + b + c = 0? Find all unique triplets in the array which gives the sum
// of zero.

// Notice that the solution set must not contain duplicate triplets.

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Input: nums = [0]
// Output: []

#include <bits/stdc++.h>
using namespace std;

// Solution: -
// Brute force approach is to iterate with three loops.
// Check if sum of all three is 0
// If true simple add to result temp and retunr result.
// To take care of duplicates, we would need to make set and store values in a
// set.
vector<vector<int>> three_sum_brute(vector<int> &nums) {
  int i = 0, j = 1, k = 2;
  int n = nums.size();

  set<vector<int>> st;

  sort(begin(nums), end(nums));

  for (i = 0; i < n - 2; i++) {
    for (j = i + 1; j < n - 1; j++) {
      for (k = i + 2; k < n; k++) {
        if (i != j && i != k && j != k) {
          if ((nums[i] + nums[j] + nums[k]) == 0) {
            vector<int> v = {nums[i], nums[j], nums[k]};
            sort(begin(v), end(v));
            st.insert(v);
          }
        }
      }
    }
  }

  vector<vector<int>> res;
  for (auto v : st) {
    res.push_back(v);
  }
  return res;
}

// Optimized Solution: -
// Sort the array.
// Use the same trick as two sum 2
// using this trick you can easily push items to set
// return the vector of set

vector<vector<int>> three_sum_opt(vector<int> &nums) {
  int i = 0, j = 1, k = 2;
  int n = nums.size();

  set<vector<int>> st;

  sort(begin(nums), end(nums));

  for (i = 0; i < n - 2; i++) {
    int left = i + 1;
    int right = n - 1;
    int tsum = 0 - nums[i];

    while (left < right) {
      int calc_sum = nums[left] + nums[right];
      if (calc_sum > tsum) {
        right -= 1;
      } else if (calc_sum < tsum) {
        left += 1;
      } else {
        // vector <int> v = {nums[i], nums[left], nums[right]};
        // sort(begin(v), end(v));
        st.insert({nums[i], nums[left], nums[right]});

        // either pointer needs to move
        // if we move both we might miss solutions
        // if we break, we will miss solutions
        left += 1;
      }
    }
  }

  vector<vector<int>> res;
  for (auto v : st) {
    res.push_back(v);
  }

  return res;
}

int main(int argc, char const *argv[]) {
  vector<int> v = {-1, 0, 1, 2, -1, -4};
  auto res = three_sum_brute(v);
  auto res2 = three_sum_opt(v);

  return 0;
}
