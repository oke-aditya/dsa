// https://leetcode.com/problems/find-all-anagrams-in-a-string/

// Given two strings s and p, return an array of all the start indices of p's anagrams in s.
// You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

#include<bits/stdc++.h>

using namespace std;


vector<int> findAnagrams(string s, string p) {

    vector<int> res;

    int k = p.size();
    int n = s.size();

    if(n < k)
    {
        return res;
    }

    map<char, int> mp2;

    for(int i=0; i<k;i++)
    {
        mp2[p[i]] += 1;
    }

    int i=0, j=0; 

    map<char, int> mp;

    // string s2 = "";

    for(j=0;j<k;j++)
    {
        mp[s[j]] += 1; 
    }

    if(mp2 == mp)
    {
        res.push_back(i);
    }

    for(j=k;j<n;j++)
    {
        // process j
        // s2 += s[j];
        mp[s[j]] += 1;
        // cout<<s2<<endl;
        // cout<<i<<endl;
        // cleanup i
        // s2.erase(s2.begin());
        mp[s[i]] -= 1;
        if(mp[s[i]] == 0)
        {
            mp.erase(s[i]);
        }
        i += 1;

        // validate after cleanup
        if(mp2 == mp)
        {
            res.push_back(i);
        }
    }

    return res;
}

