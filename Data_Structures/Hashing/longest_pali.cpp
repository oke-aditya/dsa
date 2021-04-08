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
// If count % 2 of a particular char == 0, we can place it evenly.
// No of pairs possible = 2 * (int) (itr->second / 2) 
// if count comes out as even and it has appeared odd no of times,
// we can add 1 extra char. This is for centre character
// Edge cases, if s.length = 1 return 1.


#include<bits/stdc++.h>
using namespace std;

int longest_pali(string s)
{
    if(s.length() == 1)
    {
        return 1;
    }

    map <char, int> mp;
    for(int i=0; i<s.length(); i++)
    {
        mp[s[i]] += 1;
    }

    int count = 0;

    for(auto itr=mp.begin(); itr!= mp.end(); itr++)
    {
        // Add // 2 times
        count = count +  2 * (int) (itr->second / 2);

        if(count % 2 == 0 && itr->second % 2 == 1)
        {
            count += 1;
        }
    }
    return count;
    
}


int main(int argc, char const *argv[])
{
    string s1 = "abccccdd";
    string s2 = "a";
    string s3 = "bb";

    cout<<longest_pali(s1)<<endl;
    cout<<longest_pali(s2)<<endl;
    cout<<longest_pali(s3)<<endl;
    
    return 0;
}


