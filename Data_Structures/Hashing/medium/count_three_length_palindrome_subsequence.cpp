// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

// Given a string s, return the number of unique palindromes of length three
// that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it
// is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string
// with some characters (can be none) deleted without changing the relative
// order of the remaining characters.

// Example 1:

// Input: s = "aabca"
// Output: 3
// Explanation: The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "aabca")
// - "aaa" (subsequence of "aabca")
// - "aca" (subsequence of "aabca")

// Example 2:

// Input: s = "adc"
// Output: 0
// Explanation: There are no palindromic subsequences of length 3 in "adc".

// Example 3:

// Input: s = "bbcbaba"
// Output: 4
// Explanation: The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "bbcbaba")
// - "bcb" (subsequence of "bbcbaba")
// - "bab" (subsequence of "bbcbaba")
// - "aba" (subsequence of "bbcbaba")

// Solution:
// A "3" length palindrome, exactly has first char, Middle char, end char
// For all first and end chars. If we can find unique middle chars left.
// We have the answer.

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    map<char, vector<int>> mp;

    int n = s.size();
    for (int i = 0; i < n; i++) {
      mp[s[i]].push_back(i);
    }
    // this map maintains the character, it's occurences.
    // {'a': [0, 1, 3]}

    // if the occurence are > 1
    // we would then see first and last occurence and see chars in between
    int count = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
      if (itr->second.size() > 1) {
        int f_occ = itr->second[0];
        int l_occ = itr->second[itr->second.size() - 1];

        // in between these occurences we should know how many uniq stuff popped
        // up
        unordered_set<char> st;
        for (int i = f_occ + 1; i < l_occ; i++) {
          st.insert(s[i]);
        }
        count += st.size();
      }
    }

    return count;
  }
};
