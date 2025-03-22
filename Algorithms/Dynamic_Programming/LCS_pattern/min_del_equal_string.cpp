// Given two strings ‘str1’ and ‘str2’ of size m and n respectively.
// The task is to remove/delete and insert the minimum number of characters
// from/in str1 to transform it into str2. It could be possible that the same
// character needs to be removed/deleted from one point
// of str1 and inserted to some another point.

// Input :
// str1 = "heap", str2 = "pea"
// Output :
// Minimum Deletion = 2 and
// Minimum Insertion = 1

// Efficient solutions is using LCS

// The only 2 constant letters here are LCS of (heap, pea)
// str1 and str2 be the given strings.
// m and n be their lengths respectively.
// len be the length of the longest common subsequence of str1 and str2
// minimum number of deletions minDel = m – len
// minimum number of Insertions minInsert = n – len

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

void print_min_mem(string s1, string s2) {
  int m = s1.length();
  int n = s2.length();

  int lcs = lcs_mem(s1, s2, m, n);

  int min_del = m - lcs;
  int min_insert = n - lcs;

  cout << "Minimum deletions needed " << min_del << endl;
  cout << "Minimum insertions needed " << min_insert << endl;
}

void print_min_bu(string s1, string s2) {
  int m = s1.length();
  int n = s2.length();

  int lcs = lcs_bu(s1, s2, m, n);

  int min_del = m - lcs;
  int min_insert = n - lcs;

  cout << "Minimum deletions needed " << min_del << endl;
  cout << "Minimum insertions needed " << min_insert << endl;
}

int main(int argc, char const *argv[]) {
  string str1 = "heap";
  string str2 = "pea";

  memset(dp, -1, sizeof(dp));

  print_min_mem(str1, str2);
  print_min_bu(str1, str2);

  return 0;
}
