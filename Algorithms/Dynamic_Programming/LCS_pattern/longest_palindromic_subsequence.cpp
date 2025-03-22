// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

// Given a sequence, find the length of the longest palindromic subsequence in
// it. Example Input: - GEEKSFORGEEKS Output: - 5 Longest palindromic sequence
// possible has length 5 Examples are : - EEKEE, EESEE

// Trick for palindrome think of reverse strings.
// Length of Longest Palindromic substring LCS(string a, rev(string a));

#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

int dp[100][100];

int lcs_mem(string s1, int m, string s2, int n) {
  if (m == 0) {
    return 0;
  }
  if (n == 0) {
    return 0;
  }

  if (dp[m][n] != -1) {
    return dp[m][n];
  }

  else {
    if (s1[m - 1] == s2[n - 1]) {
      dp[m][n] = (1 + lcs_mem(s1, m - 1, s2, n - 1));
    }

    else {
      dp[m][n] = (max(lcs_mem(s1, m - 1, s2, n), lcs_mem(s1, m, s2, n - 1)));
    }
  }
  return dp[m][n];
}

int lcs_bu(string s1, int m, string s2, int n) {
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
  return (dp[m][n]);
}

int lp_mem(string s1, int m) {
  int n = s1.length();
  string s2 = s1;
  reverse(s2.begin(), s2.end());

  int lcs = lcs_mem(s1, m, s2, n);

  return lcs;
}

int lp_bu(string s1, int m) {
  int n = s1.length();
  string s2 = s1;
  reverse(s2.begin(), s2.end());
  int lcs = lcs_bu(s1, m, s2, n);

  return lcs;
}

int main(int argc, char const *argv[]) {
  string s1 = "GEEKSFORGEEKS";
  int n = s1.length();

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      dp[i][j] = -1;
    }
  }

  cout << "Length of Longest palindromic subsequence " << lp_mem(s1, n) << endl;
  cout << "Length of Longest palindromic subsequence " << lp_bu(s1, n) << endl;

  return 0;
}
