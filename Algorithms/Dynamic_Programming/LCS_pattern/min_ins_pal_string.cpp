#include<bits/stdc++.h>
using namespace std;

// Given a string str, the task is to find the minimum number of characters to be inserted to convert it to palindrome.
// ab: Number of insertions required is 1 i.e. bab
// aa: Number of insertions required is 0 i.e. aa
// abcd: Number of insertions required is 3 i.e. dcbabcd

// Solution
// https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/

// This problem is very similar to minimum number of deletions to make a string plaindrome.
// No of insertions = no of deletions as we can insert the characters in other places instead of deleting.

int dp[100][100];

int lcs_mem(string s1, int m, string s2, int n)
{
    if(m == 0)
    {
        return (0);
    }
    if(n == 0)
    {
        return(0);
    }

    if(dp[m][n] != -1)
    {
        return(dp[m][n]);
    }

    else
    {
        if(s1[m-1] == s2[m-1])
        {
            dp[m][n] =  (1 + lcs_mem(s1, m-1, s2, n-1));
        }
        else
        {
            dp[m][n] = (max(lcs_mem(s1, m-1, s2, n), lcs_mem(s1, m, s2, n-1)));
        }
        return dp[m][n];
    }
}

int lcs_bu(string s1, int m, string s2, int n)
{
    if(m == 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return 0;
    }

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
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j-1]);
            }
        }
    }
    return(dp[m][n]);
}

int min_ins_pal_mem(string str, int m)
{
    string rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    int n = rev_str.length();
    int lcs = lcs_mem(str, n, rev_str, m);
    return(n - lcs);
}

int min_ins_pal_bu(string str, int m)
{
    string rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    int n = rev_str.length();
    int lcs = lcs_bu(str, n, rev_str, m);
    return(n - lcs);
}

int main(int argc, char const *argv[])
{
    string str = "geeks";
    int m = str.length();  
    memset(dp, -1, sizeof(dp));
    cout<<min_ins_pal_mem<<(str, m)<<endl;
    cout<<min_ins_pal_bu<<(str, m)<<endl;
    return 0;
}

