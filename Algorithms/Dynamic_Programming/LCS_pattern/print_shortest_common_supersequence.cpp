// Given two strings X and Y, print the shortest string that has both X and Y as subsequences.
// If multiple shortest supersequence exists, print any one of them.
// Input: X = "AGGTAB",  Y = "GXTXAYB"
// Output: "AGXGTXAYB" OR "AGGXTXAYB" 
// OR Any string that represents shortest
// supersequence of X and Y

// Input: X = "HELLO",  Y = "GEEK"
// Output: "GEHEKLLO" OR "GHEEKLLO"
// OR Any string that represents shortest 
// supersequence of X and Y

// Solution: -
// First find the dp matrix of shortest common super sequence.
// This Shortest common super sequence can be found as length(X) + length(y) - LCS(X, Y)
// Then print this dp matrix by navigating the way.
// Navigate the DP array and get the LCS
// Till x and y both the strings are 0, continue to append to the string.

#include<bits/stdc++.h>
using namespace std;

string print_scs(string str1, int m, string str2, int n)
{
    // First find the shortest_common_subsequence dp matrix;

    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            
        }
    }

    // Now get the LCS String.
    // Navigate from bottom right.
    string res="";
    int i=m, j=n;

    while(i>0 && j>0)
    {
        if(str1[i-1]==str2[j-1])
        {
            res+=str1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            res+=str1[i-1];
            i--;
        }
        else
        {
            res+=str2[j-1];
            j--;
        }
    }
    while(i>0)
    {
        res+=str1[i-1];
        i--;
    }
    while(j>0)
    {
        res+=str2[j-1];
        j--;
    }
    reverse(res.begin(), res.end());
    return res;

}

int main(int argc, char const *argv[])
{
    string x = "HELLO";
    string y = "GEEK";

    int m = x.length();
    int n = y.length();

    cout<<print_scs(x, m, y, n);

    return 0;
}

