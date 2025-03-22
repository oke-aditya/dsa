// Prining LCS
// https://www.geeksforgeeks.org/printing-longest-common-subsequence/

// We need to track the LCS Path and print it.
// First get the matrix from bottom up solution of LCS.
// Then follow and print the path

#include <bits/stdc++.h>
using namespace std;

void print_lcs(string s1, string s2, int m, int n) {
  // First get the LCS matrix
  int dp[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // Follow and print LCS
  string lc = "";

  // Start from bottommost character and find way to leftmost column or topmost
  // row
  int i = m, j = n;
  while (i > 0 && j > 0) {
    // Same character, move diagonally up.
    if (s1[i - 1] == s2[j - 1]) {
      // Add the character
      lc += s1[i - 1];
      // Move diagonally.
      i -= 1;
      j -= 1;
    }

    // If not the same, then move in direction of larger of two
    else if (dp[i - 1][j] > dp[i][j - 1]) {
      i -= 1;
    } else {
      j -= 1;
    }
  }
  reverse(lc.begin(), lc.end());

  cout << "LCS of " << s1 << " and " << s2 << " is " << lc;
}

int main(int argc, char const *argv[]) {
  string s1 = "AGGTAB";
  string s2 = "GXTXAYB";

  int m = s1.length();
  int n = s2.length();

  print_lcs(s1, s2, m, n);

  return 0;
}
