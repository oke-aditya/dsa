// Given two strings ‘X’ and ‘Y’, find the length of the longest common
// substring. Input : X = “GeeksforGeeks”, y = “GeeksQuiz” Output : 5 The
// longest common substring is “Geeks” and is of length 5.

// Same as LCS, just that if strings are not equal LCS = 0;
// Print max value in the matrix

#include <bits/stdc++.h>
using namespace std;

int lcsub_rec(string s1, string s2, int m, int n, int count) {
  int result = 0;
  if (m == 0) {
    return count;
  }
  if (n == 0) {
    return count;
  } else {
    if (s1[m - 1] == s2[n - 1]) {
      count = lcsub_rec(s1, s2, m - 1, n - 1, count + 1);
    } else {
      count = max(count, max(lcsub_rec(s1, s2, m - 1, n, 0),
                             lcsub_rec(s1, s2, m, n - 1, 0)));
    }
    return count;
  }
}

int lcsub_bu(string s1, string s2, int m, int n) {
  int dp[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = 0;
      }
    }
  }
  // Print the maximum value in this matrix;
  int max_v = -1;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      max_v = max(dp[i][j], max_v);
    }
  }
  return max_v;
}

int main(int argc, char const *argv[]) {
  string s1 = "GeeksforGeeks";
  string s2 = "GeeksQuiz";

  int m = s1.length();
  int n = s2.length();
  int count = 0;

  cout << "Length of Longest Common Substring is " << lcsub_bu(s1, s2, m, n)
       << endl;
  // cout<<"Length of Longest Common Substring is " << lcsub_mem(s1, s2, m,
  // n)<<endl;

  return 0;
}
