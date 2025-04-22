// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.

// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".

// Example 3:

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

#include<algorithm>
#include<string>
#include<vector>

using namespace std;
 
class Solution {
  public:
  
      int lcs(string s1, string s2) {
          int m = s1.size();
          int n = s2.size();
  
          vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
          // fill the grid
          for(int i=1; i<=m; i++) {
              for(int j=1; j<=n; j++) {
                  if(s1[i-1] == s2[j-1]) {
                      dp[i][j] = 1 + dp[i-1][j-1];
                  }
                  else {
                      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                  }
              }
          }
          return dp[m][n];
  
      }
  
      int minInsertions(string s) {
         // find LPS for this
          string rev_s = s;
          reverse(begin(rev_s), end(rev_s));
  
          // lcs this
          int lcs_len = lcs(s, rev_s);
          return s.size() - lcs_len;
  
  
      }
  };
