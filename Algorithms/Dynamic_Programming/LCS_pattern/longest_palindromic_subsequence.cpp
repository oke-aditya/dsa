// https://leetcode.com/problems/longest-palindromic-subsequence/description/

// Given a string s, find the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by
// deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".

// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

// Just do LCS of string and it's reverse
// 

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:

      int lcs(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m +1, vector<int> (n + 1, 0));
        
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

      int longestPalindromeSubseq(string s) {
          string s_rev = s;
          reverse(s_rev.begin(), s_rev.end());
          
          return lcs(s, s_rev);
      }
  };