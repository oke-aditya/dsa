// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

// Given two strings s1 and s2, return the lowest 
// ASCII sum of deleted characters to make two strings equal. 

// Example 1:
// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

// Solution:
// It is very similar to LCS. Just keep in mind ASCII can simply be added as integer with string indexing.
// Total ascii to delete = ASCII(s1) + ASCII(s2) - 2 * ASCII(LCS(s1, s2))
// 

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int ascii_sum = 0;
        for(int i=0; i<m; i++) {
            ascii_sum += s1[i];
        }

        for(int i=0; i<n; i++) {
            ascii_sum += s2[i];
        }

        return ascii_sum - 2 * dp[m][n];

    }
};