#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int lcs_rec(string s1, string s2, int m, int n)
{
    if(m == 0 || n == 0)
    {
        // String has no length, we won't get any subsequence
        return 0;
    }
    else
    {
        if(s1[m-1] == s2[n-1])
        {
            // Found same character
            return (1 + lcs_rec(s1, s2, m-1, n-1));
        }
        else
        {
            // We should find maximum between the other possibilites
            return(max(lcs_rec(s1, s2, m-1, n), lcs_rec(s1, s2, m, n-1)));
        }
    }
}

int lcs_mem(string s1, string s2, int m, int n)
{
    if(m == 0 || n == 0)
    {
        return 0;
    }
    if(dp[m][n] != -1)
    {
        return dp[m][n];
    }
    else
    {
        if(s1[m-1] == s2[n-1])
        {
            dp[m][n] = (1 + lcs_mem(s1, s2, m-1, n-1));
        }
        else
        {
            dp[m][n] = max(lcs_mem(s1, s2, m-1, n), lcs_mem(s1, s2, m, n-1));
        }
        return dp[m][n];
    }
}

int lcs_bu(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];
    // Initialize with 0
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
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}


int main(int argc, char const *argv[])
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    int m = s1.length();
    int n = s2.length();

    cout<<"Length of LCS: "<<lcs_rec(s1, s2, m, n)<<endl;

    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<"Length of LCS: "<<lcs_mem(s1, s2, m, n)<<endl;

    cout<<"Length of LCS: "<<lcs_bu(s1, s2, m, n)<<endl;

    return 0;
}

