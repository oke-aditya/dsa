// Find minimum number of coins that make a given value

// Given a value V, if we want to make change for V cents, and we have infinite
// supply of each of C = { C1, C2, .. , Cm} valued coins,
// what is the minimum number of coins to make the change?

// Input: coins[] = {25, 10, 5}, V = 30
// Output: Minimum 2 coins required
// We can use one coin of 25 cents and one of 5 cents

// Input: coins[] = {9, 6, 5, 1}, V = 11
// Output: Minimum 2 coins required
// We can use one coin of 6 cents and 1 coin of 5 cent

#include <bits/stdc++.h>
using namespace std;

int min_coins_rec(int coins[], int n, int change) {
  if (change == 0) {
    // We have to make 0 change, we need 0 coins.
    return 0;
  }
  if (n == 0 || change < 0) {
    // We have no coins. We can't make change, need Inf coins
    // Or the change is too small to make new coins.
    return INT_MAX - 1;
  } else {
    // Choose the coin, then we have 1 coin taken.
    // Otherwise ignore the coin
    return min(min_coins_rec(coins, n - 1, change - coins[n - 1]) + 1,
               min_coins_rec(coins, n - 1, change));
  }
}

int dp[100][100];

int min_coins_mem(int coins[], int n, int change) {
  if (change == 0) {
    return 0;
  }
  if (n == 0 || change < 0) {
    return INT_MAX - 1;
  }

  if (dp[n][change] != -1) {
    return dp[n][change];
  }

  else {
    dp[n][change] = min(min_coins_rec(coins, n - 1, change - coins[n - 1]) + 1,
                        min_coins_rec(coins, n - 1, change));
    return (dp[n][change]);
  }
}

int main(int argc, char const *argv[]) {
  int coins[] = {9, 6, 5, 1};
  int n = sizeof(coins) / sizeof(coins[0]);
  int change = 11;
  cout << "Minimum coins required is " << min_coins_rec(coins, n, change)
       << endl;

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      dp[i][j] = -1;
    }
  }

  cout << "Minimum coins required is " << min_coins_mem(coins, n, change)
       << endl;
  return 0;
}