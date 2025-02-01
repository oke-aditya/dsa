// https://leetcode.com/problems/valid-anagram/

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:

// Input: s = "rat", t = "car"
// Output: false

// Form a hasmap of s
// Check if t contains all characters of s.


#include<bits/stdc++.h>
using namespace std;


bool is_anagram(string s1, string s2)
{
    map<char, int> mp;
    for(int i=0; i<s1.length(); i++)
    {
        mp[s1[i]] += 1;
    }

    for(int i=0; i<s2.length(); i++)
    {
        mp[s2[i]] -= 1;
    }

    for(auto itr=mp.begin(); itr!= mp.end(); itr++)
    {
        if(itr->second != 0)
        {
            return false;
        }

    }
    return true;

}

// altenate with single map
bool isAnagram(string s, string t) 
{
    unordered_map<char, int> mp;

    for(auto ch: s)
    {
        mp[ch] += 1;
    }

    for(auto ch: t)
    {
        mp[ch] -= 1;
        if(mp[ch] == -1)
        {
            return false;
        }
        if(mp[ch] == 0)
        {
            mp.erase(ch);
        }
    }
    cout<<mp.size();
    return mp.size() == 0;
}


int main(int argc, char const *argv[])
{
    string s1 = "anagram";
    string s2 = "nagaram";

    string s3 = "rat";
    string s4 = "car";

    cout<<is_anagram(s1, s2)<<endl;

    cout<<is_anagram(s3, s4)<<endl;
        
    return 0;
}

