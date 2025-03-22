// https://leetcode.com/problems/kth-missing-positive-number/

// Given an array arr of positive integers sorted in a strictly increasing
// order, and an integer k.

// Find the kth positive integer that is missing from this array

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...].
// The 5th missing positive integer is 9.

// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing
// positive integer is 6.

// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000
// 1 <= k <= 1000
// arr[i] < arr[j] for 1 <= i < j <= arr.length

#include <bits/stdc++.h>
using namespace std;

void print_arr(int arr[]) {
  for (int i = 0; i < 1000; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// Solution 1
// Maintain a map which includes which elements have occured.
// Whichever has not occured, will decrease k
// Once k is 1 we return the index.
// O(n) time O(n) space.

int find_k_miss(vector<int> v, int k) {
  int arr[2005];

  memset(arr, -1, sizeof(arr));

  for (int i = 0; i < v.size(); i++) {
    arr[v[i]] = 0;
  }
  // print_arr(arr);

  for (int i = 1; i < 2005; i++) {
    if (arr[i] == -1) {
      if (k == 1) {
        return i;
      } else {
        k -= 1;
      }
    }
  }
  return 0;
}

// Solution 2
// Binary search
// Since array is in strictly increasing order.
// We can use binary search to find out element which is missing.
// https://leetcode.com/problems/kth-missing-positive-number/discuss/1004535/Python-Two-solutions-O(n)-and-O(log-n)-explained

int find_k_miss_bs(vector<int> v, int k) {
  int res;

  return res;
}

int main(int argc, char const *argv[]) {
  vector<int> v{2, 3, 4, 7, 11};
  int k = 5;

  cout << find_k_miss(v, k) << endl;
  cout << find_k_miss_bs(v, k) << endl;

  return 0;
}
