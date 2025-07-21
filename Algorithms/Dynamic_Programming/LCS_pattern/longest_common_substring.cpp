// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// Given two strings ‘X’ and ‘Y’, find the length of the longest common
// substring. Input : X = “GeeksforGeeks”, y = “GeeksQuiz” Output : 5 The
// longest common substring is “Geeks” and is of length 5.

// Same as LCS, just that if strings are not equal LCS = 0;
// Print max value in the matrix

// for substring, we don't bother of the value is not same
// Coz substring needs mandatory same values
// Result will not be in dp[m][n] coz that captures substring at that point

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int longestCommonSubstr(string& s1, string& s2) {
  int m = s1.length();
  int n = s2.length();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for(int i=1; i<=m; i++) {
    for(int j=1; j<=n; j++) {
      if(s1[i-1] == s2[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      }
      else {

        // this is the difference
        dp[i][j] = 0;
      }
    }
  }

  
  int max_value = INT_MIN;
  for(int i=0; i<=m; i++) {
      for(int j=0; j<=n; j++) {
          if(dp[i][j] > max_value) {
              max_value = max(max_value, dp[i][j]);
          }
      }
  }
  
  return max_value;
  
}

int main(int argc, char const *argv[]) {
  string s1 = "GeeksforGeeks";
  string s2 = "GeeksQuiz";

  int count = 0;

  cout << "Length of Longest Common Substring is " << longestCommonSubstr(s1, s2)
       << endl;
  // cout<<"Length of Longest Common Substring is " << lcsub_mem(s1, s2, m,
  // n)<<endl;

  return 0;
}
