// Given a string, a partitioning of the string is a palindrome partitioning
// if every substring of the partition is a palindrome.

// Input : str = “geek”
// Output : 2
// We need to make minimum 2 cuts, i.e., “g ee k”

// Input : str = “aaaa”
// Output : 0
// The string is already a palindrome.

// Input : str = “abcde”
// Output : 4

#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int is_palindrome(string s, int i, int j)
{
    if(i == j)
    {
        return true;
    }
    if(i > j)
    {
        return false;
    }

    while(i < j)
    {
        if(s[i] != s[j])
        {
            return false;
        }
        i += 1;
        j -= 1;
    }

    return true;
}

int solve(string s, int i, int j)
{
    if(i >= j)
    {
        return 0;
    }
    if(is_palindrome(s, i, j))
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int min_cut = INT_MAX;
    
    for(int k=i; k<j; k++)
    {
        int temp = 1 + solve(s, i, k) + solve(s, k+1, j);
        min_cut = min(min_cut, temp);
    }
    dp[i][j] = min_cut;
    return dp[i][j];
}

int pal_par_mem(string s, int n)
{
    int i=0, j=s.length()-1;
    int res = solve(s, i, j);
    return res;
}


int main(int argc, char const *argv[])
{
    string s = "ababbbabbababa";
    int n = s.length();
    memset(dp, -1, sizeof(dp));
    cout<<pal_par_mem(s, n)<<endl;

    return 0;
}
