#include <bits/stdc++.h>
using namespace std;

int fibonacci_rec(int n) {
  if (n <= 1) {
    return n;
  } else {
    return (fibonacci_rec(n - 1) + fibonacci_rec(n - 2));
  }
}

int dp[100];

int fibonacci_mem(int n) {
  if (dp[n] != -1) {
    return dp[n];
  } else {
    if (n <= 1) {
      return n;
    } else {
      dp[n] = (fibonacci_mem(n - 1) + fibonacci_mem(n - 2));
      return dp[n];
    }
  }
}

int fibonnaci_bu(int n) {
  int arr[n];
  arr[0] = 0;
  arr[1] = 1;

  if (n == 1 || n == 2) {
    return arr[n - 1];
  }

  for (int i = 2; i <= n; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr[n];
}

int fib(int n) {
  vector<int> res(n + 2, 0);
  res[0] = 0;
  res[1] = 1;

  // res[2] = res[0] + res[1];

  for (int i = 2; i <= n; i++) {
    res[i] = res[i - 1] + res[i - 2];
  }

  return res[n];
}

int main(int argc, char const *argv[]) {
  // Seq 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
  int n = 5;
  cout << fibonacci_rec(n) << endl;

  for (int i = 0; i < 100; i++) {
    dp[i] = -1;
  }

  cout << fibonacci_mem(n) << endl;
  cout << fibonnaci_bu(n) << endl;

  return 0;
}
