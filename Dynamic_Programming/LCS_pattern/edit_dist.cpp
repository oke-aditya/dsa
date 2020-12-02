// Given two strings str1 and str2 and below operations that can performed on str1.
// Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

#include<bits/stdc++.h>
using namespace std;

// Input:   str1 = "geek", str2 = "gesek"
// Output:  1
// We can convert str1 into str2 by inserting a 's'.

// Input:   str1 = "cat", str2 = "cut"
// Output:  1
// We can convert str1 into str2 by replacing 'a' with 'u'.

int edit_rec(string s1, string s2, int m, int n)
{
    // If first string is empty, we need to do other n insertions
    if(m == 0)
    {
        return n;
    }
    // If second string is empty we need to do other m insertions.
    if(n == 0)
    {
        return m;
    }
    else
    {
        // If equal we don't need to edit.
        if(s1[m-1] == s2[n-1])
        {
            return (edit_rec(s1, s2, m-1, n-1));
        }
        else
        {
            // We have to make 1 edit as they are not equal.
            return (1 + min({edit_rec(s1, s2, m, n - 1), edit_rec(s1, s2, m - 1, n), edit_rec(s1, s2, m - 1, n - 1)}));
        }
    }
}

int dp[100][100];

int edit_mem(string s1, string s2, int m, int n)
{
    if(m == 0)
    {
        return n;
    }
    if(n == 0)
    {
        return m;
    }
    if(dp[m][n] != -1)
    {
        return dp[m][n];
    }

    else
    {
        if(s1[m-1] == s2[n-1])
        {
            dp[m][n] = edit_mem(s1, s2, m-1, n-1);
        }
        else
        {
            dp[m][n] = (1 + min({edit_mem(s1, s2, m, n - 1), edit_mem(s1, s2, m - 1, n), edit_mem(s1, s2, m - 1, n - 1)}));
        }
        return dp[m][n];
    }
}

int edit_bu(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0)
            {
                dp[i][j] = j;
            }
            else if(j == 0)
            {
                dp[i][j] = i;
            }
        }
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
    }
    return dp[m][n];
}

int main(int argc, char const *argv[])
{
    string str1 = "sunday";
    string str2 = "saturday";
    memset(dp, -1, sizeof(dp));
    cout << edit_rec(str1, str2, str1.length(), str2.length())<<endl;
    cout << edit_mem(str1, str2, str1.length(), str2.length())<<endl;
    cout << edit_bu(str1, str2, str1.length(), str2.length())<<endl;
    return 0;
}

