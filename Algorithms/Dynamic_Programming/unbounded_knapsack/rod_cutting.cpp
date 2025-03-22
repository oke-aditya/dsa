// Given a rod of length n inches and an array of prices that contains prices of
// all pieces of size smaller than n. Determine the maximum value obtainable by
// cutting up the rod and selling the pieces.

// length   | 1   2   3   4   5   6   7   8
// --------------------------------------------
// price    | 1   5   8   9  10  17  17  20

// This question is an exact variant of unbounded knapsack. It is just a
// reframe.

#include <bits/stdc++.h>
using namespace std;

int rod_cut_rec(int price[], int length[], int n, int max_len) {
  if (n == 0) {
    return 0;
  }
  if (max_len == 0) {
    return 0;
  } else {
    if (length[n - 1] > max_len) {
      return rod_cut_rec(price, length, n - 1, max_len);
    } else {
      return (max(
          price[n - 1] + rod_cut_rec(price, length, n, max_len - length[n - 1]),
          rod_cut_rec(price, length, n - 1, max_len)));
    }
  }
}

int dp[100][100];

int rod_cut_mem(int price[], int length[], int n, int max_len) {
  if (dp[n][max_len] != -1) {
    return dp[n][max_len];
  }

  else {
    if (n == 0) {
      return 0;
    }
    if (max_len == 0) {
      return 0;
    } else {
      if (length[n - 1] > max_len) {
        dp[n][max_len] = rod_cut_rec(price, length, n - 1, max_len);
        return dp[n][max_len];
      } else {
        dp[n][max_len] =
            max(price[n - 1] +
                    rod_cut_rec(price, length, n, max_len - length[n - 1]),
                rod_cut_rec(price, length, n - 1, max_len));
        return dp[n][max_len];
      }
    }
  }
}

int rod_cut_bu(int price[], int length[], int n, int max_len) {
  int dp[n + 1][max_len + 1];

  for (int i = 0; i < max_len; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      }
    }
  }

  for (int i = 1; i < max_len; i++) {
    for (int j = 1; j < n; j++) {
      if (length[i - 1] > max_len) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(length[i - 1] + dp[i][j - max_len - length[i - 1]],
                       dp[i - 1][j]);
      }
    }
  }
  return dp[n][max_len];
}

int main(int argc, char const *argv[]) {
  int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int n = sizeof(price) / sizeof(price[0]);
  int length[n];
  for (int i = 0; i < n; i++) {
    length[i] = i + 1;
  }
  int max_len = n;

  cout << "Maxmum obtained value  is " << rod_cut_rec(price, length, n, max_len)
       << endl;

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      dp[i][j] = -1;
    }
  }

  cout << "Maxmum obtained value  is " << rod_cut_mem(price, length, n, max_len)
       << endl;
  cout << "Maxmum obtained value  is " << rod_cut_bu(price, length, n, max_len)
       << endl;

  return 0;
}
