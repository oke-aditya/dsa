// https://leetcode.com/problems/shortest-common-supersequence/description/

// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. 
// If there are multiple valid strings, return any of them.
// A string s is a subsequence of string t if deleting some 
// number of characters from t (possibly 0) results in the string s.

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.

// Example 2:

// Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// Output: "aaaaaaaa"

// LCS will give you the common characters that are needed to be deleted.
// Hence,
// Length of the shortest supersequence
// = (Sum of lengths of given two strings)
// - (Length of LCS of two given strings)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
      int lcs(string str1, string str2, int m, int n, vector<vector<int>> &dp) {
          for(int i=1; i<=m; i++) {
              for(int j=1; j<=n; j++) {
                  if(str1[i-1] == str2[j-1]) {
                      dp[i][j] = 1 + dp[i-1][j-1];
                  }
                  else {
                      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                  }
              }
          }
          return dp[m][n];
      }
  
      string shortestCommonSupersequence(string str1, string str2) {
          
          int m = str1.size();
          int n = str2.size();
  
          vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
          
          int lcs_len = lcs(str1, str2, m, n, dp);
  
          string res = "";
          int i = m, j = n;
  
          // Backtracking to construct the shortest common supersequence
          while(i > 0 && j > 0) {
              if(str1[i-1] == str2[j-1]) {
                  // If the characters are the same, it's part of the LCS
                  res += str1[i-1];
                  i--;
                  j--;
              } else if(dp[i-1][j] > dp[i][j-1]) {
                  // If moving up in the dp table gives a higher value, add str1[i-1]
                  res += str1[i-1];
                  i--;
              } else {
                  // If moving left in the dp table gives a higher value, add str2[j-1]
                  res += str2[j-1];
                  j--;
              }
          }
  
          // If there are characters left in str1, add them
          while(i > 0) {
              res += str1[i-1];
              i--;
          }
  
          // If there are characters left in str2, add them
          while(j > 0) {
              res += str2[j-1];
              j--;
          }
  
          // The result string is constructed in reverse, so reverse it
          reverse(res.begin(), res.end());
          
          return res;
      }
  };
  