// https://leetcode.com/problems/subarray-sum-equals-k/

// Hashmap solution code also works for
// https://leetcode.com/problems/binary-subarrays-with-sum/

// Also works for
// https://binarysearch.com/problems/Number-of-Sublists-With-Sum-of-Target

// Given an array of integers nums and an integer k, return the total number of
// continuous subarrays whose sum equals to k.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

#include <bits/stdc++.h>
using namespace std;

// This does not work for negative numbers.

int subarr_ksum(vector<int> v, int k) {
  int i = 0, j = 0;
  int n = v.size();
  // Count of elements whose sum is k.
  int count = 0;
  int win_sum = 0;

  for (j = 0; j < n; j++) {
    // Add each element to windoow sum.
    win_sum += v[j];
    if (win_sum == k) {
      // We count this window.
      count += 1;
    }

    else if (win_sum > k) {
      // We need to cleanup elements.
      // Cleanup elements till window sum
      // is greater
      while (win_sum > k) {
        // Clean left
        win_sum -= v[i];
        i += 1;
      }

      // If after cleaning we reach the sum
      if (win_sum == k) {
        count += 1;
      }
    }
  }
  return count;
}

// Brute force solution
int subarr_ksum(vector<int> v, int k) {
  int count = 0, cum_sum = 0;

  for (int i = 0; i < v.size(); i++) {
    cum_sum = 0;
    for (int j = i; j < v.size(); j++) {
      cum_sum += v[j];
      if (cum_sum == k) {
        count += 1;
      }
    }
  }
  return count;
}

// Approach 4: Using Hashmap

// Based on these thoughts, we make use of a hashmap
// which is used to store the cumulative sum up to all the indices possible
// along with the number of times the same sum occurs. We store the data in the
// form:
//  We traverse over the array and keep on finding the cumulative sum.
// Every time we encounter a new sum, we make a new entry in the hashmap
// corresponding to that sum. If the same sum occurs again, we increment the
// count corresponding to that sum in the hashmap. Further, for every sum
// encountered, we also determine the number of times the sum ksum−k has
// occurred already, since it will determine the number of times a subarray with
// sum k has occurred up to the current index. We increment
//  by the same amount.

int subarr_map(vector<int> v, int k) {
  int count = 0, cum_sum = 0;
  map<int, int> mp;
  mp[0] = 1;

  for (int i = 0; i < v.size(); i++) {
    cum_sum += v[i];
    count += mp[cum_sum - k];
    mp[cum_sum] += 1;
  }

  return count;
}

int main(int argc, char const *argv[]) {
  vector<int> v1 = {1, 1, 1};
  int k1 = 2;

  vector<int> v2 = {1, 2, 3};
  int k2 = 3;

  auto res1 = subarr_ksum(v1, k1);
  auto res2 = subarr_ksum(v2, k2);

  cout << res1 << endl;
  cout << res2 << endl;

  return 0;
}
