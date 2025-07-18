// Given two strings str1 and str2 and below operations that can performed on
// str1. Find minimum number of edits (operations) required to convert ‘str1’
// into ‘str2’.

#include <bits/stdc++.h>
using namespace std;

// Input:   str1 = "geek", str2 = "gesek"
// Output:  1
// We can convert str1 into str2 by inserting a 's'.

// Input:   str1 = "cat", str2 = "cut"
// Output:  1
// We can convert str1 into str2 by replacing 'a' with 'u'.

int edit_dist_bu(string word1, int m, string word2, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0) {
                dp[i][j] = j;
            }

            else if(j == 0) {
                dp[i][j] = i;
            }

        }
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
    
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }

            else {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
        }
    }

    return dp[m][n];
}

int minDistance(string word1, string word2) {
    int m = word1.size(); 
    int n = word2.size();

    return edit_dist_bu(word1, m, word2, n);

}