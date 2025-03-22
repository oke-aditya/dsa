// Partition problem is to determine whether a
// given set can be partitioned into two subsets such that the sum of elements
// in both subsets is the same.

// arr[] = {1, 5, 11, 5}
// Output: true
// The array can be partitioned as {1, 5, 5} and {11}

// arr[] = {1, 5, 3}
// Output: false
// The array cannot be partitioned into equal sum sets.

#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

bool is_subset_sum(int arr[], int sum, int n) {
  if (dp[n][sum] != -1) {
    return dp[n][sum];
  }

  // // base conditions
  if (n == 0) {
    if (sum == 0) {
      return 1;
    }
    return 0;
  }

  else {
    if (arr[n - 1] > sum) {
      dp[n][sum] = is_subset_sum(arr, sum, n - 1);
      return dp[n][sum];
    } else {
      dp[n][sum] = (is_subset_sum(arr, sum, n - 1) ||
                    is_subset_sum(arr, sum - arr[n - 1], n - 1));
      return dp[n][sum];
    }
  }
}

bool equal_sum(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  if (sum % 2 == 0) {
    return is_subset_sum(arr, sum / 2, n);
  } else {
    return false;
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {3, 1, 5, 9, 12};
  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      dp[i][j] = -1;
    }
  }

  // Function call
  if (equal_sum(arr, n)) {
    cout << "Can be divided into two subsets of equal sum";
  } else {
    cout << "Can not be divided into two subsets of equal sum";
  }

  return 0;
}
