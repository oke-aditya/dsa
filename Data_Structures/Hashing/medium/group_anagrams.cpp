// https://leetcode.com/problems/group-anagrams/

// Given an array of strings strs, group the anagrams together.
// You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:

// Input: strs = [""]
// Output: [[""]]

// Solution: -
// In a map keep key as string, and push all sorted vectors as values.
// use a temp string to sort these.
// Using key as this temp value, push the s string.


#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> group_anagrams(vector<string>& strs)
{
    vector<vector<string>> res;

    map<string, vector<string>> mp;

    for(auto word: strs)
    {
        string original_word = word;
        sort(begin(word), end(word));
        
        // we have found it
        if(mp.find(word) != mp.end())
        {
            vector<string> group = mp[word];
            group.push_back(original_word);
            mp[word] = group;
        }

        else
        {
            vector<string> group;
            group.push_back(original_word);
            mp[word] = group;
        }
    }

    for(auto itr=mp.begin(); itr != mp.end(); itr++)
    {
        res.push_back(itr->second);
    }

    return res;
    
}

int main(int argc, char const *argv[])
{
    vector<string> v {"eat","tea","tan","ate","nat","bat"};

    
    return 0;
}

