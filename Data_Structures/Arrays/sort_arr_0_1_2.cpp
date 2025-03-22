// https://leetcode.com/problems/sort-colors/

// Given an array nums with n objects colored red, white, or blue, sort

// them in-place so that objects of the same color are adjacent, with the colors
// in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and
// blue, respectively.

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Could you solve this problem without using the library's sort function?
// Could you come up with a one-pass algorithm using only O(1) constant space?

#include <bits/stdc++.h>
using namespace std;

// 1. Naive solution: -
// Sort the array.
// Time Complexity O(nlogn)
// Space Complexity = O(1)

void print_v(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

// 2. Counting Sort

// Count number of 0s
// Count number of 1s
// Count number of 2s.
// To existing array overwrite 0 x number of 0s, 1 x number of 1s, 2 x number of
// 2s

void sort_colors_counting(vector<int> &nums) {
  map<int, int> mp;
  for (int i = 0; i < nums.size(); i++) {
    mp[nums[i]] += 1;
  }

  int j = 0;

  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    int val = itr->first;
    int n = itr->second;
    // cout<<val<<" "<<n<<endl;
    for (int i = 0; i < n; i++) {
      nums[j] = val;
      j += 1;
    }
  }
}

// 3. Dutch National Flag. 3 Pointer technique.
// Keep 3 pointers, low, mid, high.
// Accumulate
// 0s in arr[0 ... low - 1]
// 2s in arr[high+1 ... ]
// 1s in between arr[low ... mid + 1]

void sort_colors(vector<int> &nums) {
  int n = nums.size();
  int low = 0, mid = 0, high = n - 1;

  while (mid <= high) {
    if (nums[mid] == 0) {
      swap(nums[low], nums[mid]);
      // Move low to right after swapping.
      low += 1;
      // Shift mid ahead.
      mid += 1;
    } else if (nums[mid] == 1) {
      // Since we always wanted mid to have 1s
      mid += 1;
    } else if (nums[mid] == 2) {
      swap(nums[mid], nums[high]);

      // Move high to left.
      high -= 1;
      // Do not shift mid here, we might need to check again.
    }
  }
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  vector<int> nums2 = {2, 0, 2, 1, 1, 0};

  sort_colors_counting(nums);
  print_v(nums);

  sort_colors(nums2);
  print_v(nums2);

  return 0;
}
