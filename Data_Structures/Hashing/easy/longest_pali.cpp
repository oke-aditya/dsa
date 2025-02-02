// https://leetcode.com/problems/longest-palindrome/

// Given a string s which consists of lowercase or uppercase letters,
// return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

// Input: s = "abccccdd"
// Output: 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

// Input: s = "a"
// Output: 1

// Input: s = "bb"
// Output: 2

// Solution: -
// We just nned the length
// Maintain hashmap of all chars
// If count % 2 of a particular char == 0, we can take all occurence
// if the count is odd, we can take all the even number of occurences.
// we just need 1 extra if we have an odd char.

#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) 
{
    map<char, int> mp;
    for(auto ch: s)
    {
        mp[ch] += 1;
    }

    int max_len = 0;
    bool has_odd = false;
    
    for(auto itr=mp.begin(); itr != mp.end(); itr++)
    {
        int n_occ = itr->second;
        
        // is event, we can take the whole
        if((n_occ % 2) == 0)
        {
            max_len +=  n_occ;
        }

        else
        {
            max_len += n_occ - 1;
            has_odd = true;
        }
    }

    if(has_odd) 
        return max_len + 1;
    else
        return max_len;
}


int main(int argc, char const *argv[])
{
    string s1 = "abccccdd";
    string s2 = "a";
    string s3 = "bb";

    cout<<longestPalindrome(s1)<<endl;
    cout<<longestPalindrome(s2)<<endl;
    cout<<longestPalindrome(s3)<<endl;
    
    return 0;
}


