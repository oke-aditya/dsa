// https://leetcode.com/problems/longest-string-chain/

// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in 
// wordA without changing the order of the other characters to make it equal to wordB.

//    For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

// Solution

// Just a variant of LIS, where characters separate by 1 character difference
// Sort the words by order of length first

#include<bits/stdc++.h>

using namespace std;

bool comp(string &s1, string &s2)
{
    return s2.size() > s1.size();
}

bool compare(string &s1, string &s2)
{
    // two pointer logic to filter these.
    int i=0, j=0;

    // s1 is previous.
    // s2 is next string.

    // both can differ by just 1 size.
    if(s1.size() + 1 != s2.size())
    {
        return false;
    }

    while(j<s2.size())
    {
        if(s1[i] == s2[j])
        {
            i += 1;
            j += 1;
        }
        // the second string can go 1 more.
        else
        {
            j += 1;
        }
    }

    // if both have reached the end.
    return (i == s1.size() && j == s2.size());

}

void print_v(vector<string> v)
{
    for(auto x: v)
    {
        cout<<x<<" ";
    }
}

int longestStrChain(vector<string>& words) 
{
    sort(begin(words), end(words), comp);

    // print_v(words);
    // cout<<endl;

    int n = words.size();
    vector<int> dp(n + 1, 1);

    int res = 1;                                                                

    for(int i=0; i<n; i++)
    {
        for(int prev=0; prev<i; prev++)
        {
            // if there is difference of 1 character
            if(compare(words[prev], words[i]))
            {
                // this forms a string chain, add it to dp.
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
            res = max(dp[i], res);
        }
    }
    return res;

}