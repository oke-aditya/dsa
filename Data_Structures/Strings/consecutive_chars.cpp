// https://leetcode.com/problems/consecutive-characters/

// Consecutive Characters

// Given a string s, the power of the string is the maximum length of a non-empty
// substring that contains only one unique character.

// Return the power of the string.

// Input: s = "leetcode"
// Output: 2
// Explanation: The substring "ee" is of length 2 with the character 'e' only.

// Input: s = "abbcccddddeeeeedcba"
// Output: 5
// Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

// Input: s = "triplepillooooow"
// Output: 5

// Input: s = "hooraaaaaaaaaaay"
// Output: 11

// Input: s = "tourist"
// Output: 1


#include<bits/stdc++.h>
using namespace std;

// Solutino

// In other words, we need to find the Longest
// Substring with the same characters.

// We can iterate over the given string, and use a
// variable count to record the length of that substring.

// When the next character is the same as the previous one,
// we increase count by one. Else, we reset count to 1.

// With this method, when reaching the end of a substring with the
// same characters, count will be the length of that substring,
// since we reset the count when that substring starts,
// and increase count when iterate that substring

int maxPower(string s)
{
    int count = 0, max_count = 0;
    char prev = s[0];
    for(char c: s)
    {
        if(c == prev)
        {
            count += 1;
        }
        else
        {
            // No length
            prev = c;
            count = 1;
        }
        max_count = max(count, max_count);
    }
    return max_count;
        
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

