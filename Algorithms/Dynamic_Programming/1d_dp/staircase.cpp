#include <bits/stdc++.h>
using namespace std;

// There are n stairs in total, x can either climb 1, 2 or 3 stairs in a single
// move. In how many ways can x reach the last stair i.e. the nth stair. Input :
// 4 Output : 7

// Input : 3
// Output : 4

int staircase_rec(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else if (n == 2) {
    return 2;
  } else {
    return (staircase_rec(n - 1) + staircase_rec(n - 2) + staircase_rec(n - 3));
  }
}

int dp[100];

int staircase_mem(int n) {
  if (dp[n] != -1) {
    return dp[n];
  } else {
    if (n == 0 || n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    } else {
      dp[n] =
          (staircase_mem(n - 1) + staircase_mem(n - 2) + staircase_mem(n - 3));
      return dp[n];
    }
  }
}

int staircase_td(int n) {
  int arr[n];
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  if (n == 0 || n == 1) {
    return 1;
  } else if (n == 2) {
    return 2;
  } else {
    for (int i = 2; i < n + 1; i++) {
      arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]);
    }
    return arr[n];
  }
}

int climbStairs(int n) {
  vector<int> res(n + 4, 0);
  res[0] = 0;
  res[1] = 1;
  res[2] = 2;
  res[3] = 3;

  for (int i = 4; i <= n; i++) {
    res[i] = res[i - 1] + res[i - 2];
  }

  return res[n];
}

int main(int argc, char const *argv[]) {
  int n = 4;
  cout << staircase_rec(n) << endl;
  for (int i = 0; i < 100; i++) {
    dp[i] = -1;
  }
  cout << staircase_mem(n) << endl;
  cout << staircase_td(n) << endl;
  return 0;
}
