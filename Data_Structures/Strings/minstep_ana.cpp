// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

// Given two equal-size strings s and t. In one step you can choose any character of t and replace it with another character.

// Return the minimum number of steps to make t an anagram of s.

// An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

// Example 1:

// Input: s = "bab", t = "aba"
// Output: 1
// Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

// Example 2:

// Input: s = "leetcode", t = "practice"
// Output: 5
// Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.

// Example 3:

// Input: s = "anagram", t = "mangaar"
// Output: 0
// Explanation: "anagram" and "mangaar" are anagrams. 


#include<bits/stdc++.h>
using namespace std;

int minSteps(string s, string t) 
{
    unordered_map<char, int> mp1;

    int min_swaps = 0;
    for(auto c: s)
    {
        mp1[c] += 1;
    }

    for(auto c: t)
    {
        mp1[c] -= 1;
    }

    for(auto itr = mp1.begin(); itr!= mp1.end(); itr++)
    {
        if(itr->second < 0)
        {
            min_swaps += itr->second;
        }
    }

    return abs(min_swaps);

}

