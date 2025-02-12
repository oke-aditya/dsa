// https://leetcode.com/problems/sort-characters-by-frequency/
// Given a string s, sort it in decreasing order 
// based on the frequency of characters, and return the sorted string.

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' 
// and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. 
// Therefore "eetr" is also a valid answer.

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so "aaaccc" 
// is also a valid answer.
// Note that "cacaca" is 
// incorrect, as the same characters must be together.

#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    unordered_map <char, int> mp;
    
    // Create map of all characters.
    for(auto ch: s)
    {
        mp[ch] += 1;
    }
    
    string res = "";
    
    
    // Create a maxheap
    priority_queue<pair<int, char>> maxh;
    
    for(auto itr=mp.begin(); itr != mp.end(); itr++)
    {
        maxh.push({itr->second, itr->first});
    }
    
    while(!maxh.empty())
    {
        int ct = maxh.top().first;
        char ch = maxh.top().second;
        
        while(ct>0)
        {
            res += ch;
            ct -= 1;
        }
        
        maxh.pop();
    }
    return res;
}

