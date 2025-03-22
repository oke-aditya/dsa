// Given two strings str1 and str2, the task is to find the length of the
// shortest string that has both str1 and str2 as subsequences.

// Input:   str1 = "geek",  str2 = "eke"
// Output: 5
// Explanation:
// String "geeke" has both string "geek"
// and "eke" as subsequences.

// Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
// Output:  9
// Explanation:
// String "AGXGTXAYB" has both string
// "AGGTAB" and "GXTXAYB" as subsequences.

// The basic logic behind this problem is
// LCS will give you the common characters that are needed to be deleted.
// Hence,
// Length of the shortest supersequence
// = (Sum of lengths of given two strings)
// - (Length of LCS of two given strings)

#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int lcs_mem(string s1, string s2, int m, int n) {
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
      dp[m][n] = (1 + lcs_mem(s1, s2, m - 1, n - 1));
    } else {
      dp[m][n] = (max(lcs_mem(s1, s2, m - 1, n), lcs_mem(s1, s2, m, n - 1)));
    }
    return dp[m][n];
  }
}

int lcs_bu(string s1, string s2, int m, int n) {
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
  return dp[m][n];
}

int super_seq_mem(string s1, string s2, int m, int n) {
  return (m + n - lcs_mem(s1, s2, m, n));
}

int super_seq_bu(string s1, string s2, int m, int n) {
  return (m + n - lcs_bu(s1, s2, m, n));
}

int main(int argc, char const *argv[]) {
  string s1 = "AGGTAB";
  string s2 = "GXTXAYB";

  int m = s1.length();
  int n = s1.length();

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      dp[i][j] = -1;
    }
  }

  cout << "Length of supersequnce: " << super_seq_mem(s1, s2, m, n) << endl;
  cout << "Length of supersequnce: " << super_seq_bu(s1, s2, m, n) << endl;

  return 0;
}
