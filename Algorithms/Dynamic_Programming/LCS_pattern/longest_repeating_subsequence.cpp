// Longest Repeated Subsequence

// Given a string, print the longest repeating subsequence such that the two
// subsequence don’t have same string character at same position, i.e., any i’th
// character in the two subsequences shouldn’t have the same index in the
// original string.

// Input: str = "aabb"
// Output: "ab"

// Input: str = "aab"
// Output: "a"
// The two subsequence are 'a'(first) and 'a'
// (second). Note that 'b' cannot be considered
// as part of subsequence as it would be at same
// index in both.

// Solution
// The idea is to find the LCS(str, str)
// where str is the input string with the restriction that
// when both the characters are same, they shouldn’t be on the same index in the
// two strings.
//

#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int lcs_mem(string s1, int m, string s2, int n) {
  if (m == 0) {
    return (0);
  }
  if (n == 0) {
    return (0);
  }
  if (dp[m][n] != -1) {
    return dp[m][n];
  } else {
    if (s1[m - 1] == s2[n - 1] && (m != n)) {
      dp[m][n] = (1 + lcs_mem(s1, m - 1, s2, n - 1));
    } else {
      dp[m][n] = (max(lcs_mem(s1, m - 1, s2, n), lcs_mem(s1, m, s2, n - 1)));
    }
    return dp[m][n];
  }
}

int long_rep_sub_mem(string s1, int m) {
  string s2 = s1;
  int n = s1.length();
  int res = lcs_mem(s1, m, s2, n);
  return res;
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
      if (s1[i - 1] == s2[j - 1] && (i != j)) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[m][n];
}

int long_rep_sub_bu(string s1, int m) {
  string s2 = s1;
  int n = s1.length();
  int res = lcs_bu(s1, m, s2, n);
  return res;
}

int main(int argc, char const *argv[]) {
  string str = "aabb";
  int m = str.length();
  memset(dp, -1, sizeof(dp));

  cout << endl << long_rep_sub_mem(str, m) << endl;
  cout << endl << long_rep_sub_bu(str, m) << endl;

  return 0;
}
