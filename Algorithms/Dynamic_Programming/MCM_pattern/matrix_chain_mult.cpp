// Given a sequence of matrices, find the most efficient way to multiply these
// matrices together. The problem is not actually to perform the
// multiplications, but merely to decide in which order to perform the
// multiplications.

#include <bits/stdc++.h>
using namespace std;

// Input: p[] = {40, 20, 30, 10, 30}
// Output: 26000
// There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
// Let the input 4 matrices be A, B, C and D.  The minimum number of
// multiplications are obtained by putting parenthesis in following way
// (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

// Input: p[] = {10, 20, 30, 40, 30}
// Output: 30000
// There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30.
// Let the input 4 matrices be A, B, C and D.  The minimum number of
// multiplications are obtained by putting parenthesis in following way
// ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

// Input: p[] = {10, 20, 30}
// Output: 6000
// There are only two matrices of dimensions 10x20 and 20x30. So there
// is only one way to multiply the matrices, cost of which is 10*20*30

// Solution

// Paritition the input array at i, j and k
// At position K, we solve problems on left side as well as right side.
// It's obtimal substructure is to multiple at both the ends at every position.
// mcm(arr, i, k) + mcm(arr, k+1, j) and solve the middle sub problem arr[i-1] *
// arr[k] * arr[j] Computer minimum at each step and return the overall minimum
// solution.

int mcm_rec(int arr[], int i, int j) {
  if (i >= j) {
    // If our partitiaon starts exceeding.
    return 0;
  }
  int k, min_cost = INT_MAX, count;

  // Iterate k from i to j, k will partition the problem to substructure.

  for (k = i; k < j; k++) {
    count = mcm_rec(arr, i, k) + mcm_rec(arr, k + 1, j) +
            arr[i - 1] * arr[k] * arr[j];
  }

  min_cost = min(min_cost, count);

  return min_cost;
}

int dp[100][100];

int mcm_mem(int arr[], int i, int j) {
  if (i >= j) {
    return 0;
  }

  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int k, min_cost = INT_MAX, count;

  // Again iterate and store the solutions

  for (k = i; k < j; k++) {
    count = mcm_rec(arr, i, k) + mcm_rec(arr, k + 1, j) +
            arr[i - 1] * arr[k] * arr[j];
  }
  min_cost = min(min_cost, count);

  dp[i][j] = min_cost;

  return dp[i][j];
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Minimum number of multiplications is " << mcm_rec(arr, 1, n - 1)
       << endl;

  memset(dp, -1, sizeof(dp));

  cout << "Minimum number of multiplications is " << mcm_mem(arr, 1, n - 1)
       << endl;

  return 0;
}
