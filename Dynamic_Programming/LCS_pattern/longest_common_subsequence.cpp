#include<bits/stdc++.h>
using namespace std;

int lcs_rec(string s1, string s2, int m, int n)
{
    if(m == 0 || n == 0)
    {
        // String has no legth, we won't get any subsequence
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

int main(int argc, char const *argv[])
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    int m = s1.length();
    int n = s2.length();

    cout<<"Length of LCS: "<<lcs_rec(s1, s2, m, n);

    return 0;
}

