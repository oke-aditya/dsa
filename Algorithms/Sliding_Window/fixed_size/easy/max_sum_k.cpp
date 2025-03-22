// Given an array of integers of size ‘n’.
// Our aim is to calculate the maximum sum of ‘k’
// consecutive elements in the array.

// Input  : arr[] = {100, 200, 300, 400}
//          k = 2
// Output : 700

// Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
//          k = 4
// Output : 39
// We get maximum sum by adding subarray {4, 2, 10, 23}
// of size 4.

// https://www.geeksforgeeks.org/window-sliding-technique/

#include <bits/stdc++.h>
using namespace std;

int max_sum_k_brute(int arr[], int n, int k) {
  int max_sum = INT_MIN;
  for (int i = 0; i < n - k + 1; i++) {
    int current_sum = 0;
    for (int j = 0; j < k; j++) {
      current_sum += arr[i + j];
    }
    max_sum = max(current_sum, max_sum);
  }
  return max_sum;
}

// This is the sliding window approach
int max_sum_k_opt(int arr[], int n, int k) {
  // Compute sum till the window
  int max_sum = 0;

  for (int j = 0; j < k; j++) {
    max_sum += arr[j];
  }
  int window_sum = max_sum;
  // Compute one element at a time.
  int i = 0;  // Starting pointer
  for (int j = k; j < n; j++) {
    window_sum += arr[j] - arr[i];
    max_sum = max(max_sum, window_sum);
    i += 1;
  }
  return max_sum;
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 4;
  auto maxs = max_sum_k_opt(arr, n, k);
  cout << maxs << endl;

  return 0;
}
