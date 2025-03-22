#include <bits/stdc++.h>
using namespace std;

// Given a string of size ‘n’.
// The task is to remove or delete the minimum number of characters from the
// string so that the resultant string is a palindrome.

// Input : aebcbda
// Output : 2
// Remove characters 'e' and 'd'
// Resultant string will be 'abcba'
// which is a palindromic string

// Input : geeksforgeeks
// Output : 8

// Solution: -
// Find length of longest palindormic subsequence.
// The remaining characters have to be deleted to make the resultant string to a
// palindrome. minimum number of deletions = n - len of longest palindromic
// substring.

int dp[100][100];

int pal_subs_mem(string s1, int m, string s2, int n) {
  if (m == 0) {
    return 0;
  }
  if (n == 0) {
    return 0;
  }
  if (dp[m][n] != -1) {
    return (dp[m][n]);
  } else {
    if (s1[m - 1] == s2[n - 1]) {
      dp[m][n] = (1 + pal_subs_mem(s1, m - 1, s2, n - 1));
    } else {
      dp[m][n] =
          (max(pal_subs_mem(s1, m - 1, s2, n), pal_subs_mem(s1, m, s2, n - 1)));
    }
    return dp[m][n];
  }
}

int pal_subs_bu(string s1, int m, string s2, int n) {
  int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
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
  return dp[m][n];
}

int min_deletions_pal_mem(string s, int m) {
  string rev_str = s;
  reverse(rev_str.begin(), rev_str.end());
  int n = rev_str.length();

  int pal_len = pal_subs_mem(s, m, rev_str, n);

  return (m - pal_len);
}

int min_deletions_pal_bu(string s, int m) {
  string rev_str = s;
  reverse(rev_str.begin(), rev_str.end());
  int n = rev_str.length();

  int pal_len = pal_subs_bu(s, n, rev_str, n);

  return (m - pal_len);
}

int main(int argc, char const *argv[]) {
  string str = "geeksforgeeks";
  int n = str.length();
  memset(dp, -1, sizeof(dp));

  cout << min_deletions_pal_mem(str, n) << endl;
  cout << min_deletions_pal_bu(str, n) << endl;

  return 0;
}
