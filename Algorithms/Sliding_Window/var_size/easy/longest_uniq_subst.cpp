// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Given a string s, find the length of the
// longest substring without repeating characters.
// Note that k is not given.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Example 4:

// Input: s = ""
// Output: 0

// Solution

// Size of window == Size of map. Then there are no repeating chars.

// No repeating character -> All unique characters.

#include <bits/stdc++.h>
using namespace std;

int longest_uniq_subst(string s)
{
    int i = 0, j = 0;
    int max_win_size = -1;
    int n = s.length();

    unordered_map<char, int> mp;

    for (j = 0; j < n; j++)
    {
        // Process each element
        mp[s[j]] += 1;

        // If number of unique chars == current windows length
        if ((mp.size() == (j - i + 1)))
        {
            // Store the ans
            max_win_size = max(max_win_size, (j - i + 1));
        }

        // If number of unique chars < current window length.
        else if ((mp.size() < (j - i + 1)))
        {
            // Cleanup left side.
            while ((mp.size() < (j - i + 1)))
            {
                // Cleanup left side i.
                // Remove counts from map.

                mp[s[i]] -= 1;

                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i += 1;
            }
            if ((mp.size() == (j - i + 1)))
            {
                // Store the answer
                max_win_size = max(max_win_size, (j - i + 1));
            }
        }
    }
    return max_win_size;
}

int main(int argc, char const *argv[])
{
    string s = "abcabcbb";

    cout << longest_uniq_subst(s) << endl;

    string s2 = "bbbbb";

    cout << longest_uniq_subst(s2) << endl;

    return 0;
}
