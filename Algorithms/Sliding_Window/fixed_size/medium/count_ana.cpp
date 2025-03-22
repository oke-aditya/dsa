// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// https://leetcode.com/problems/permutation-in-string/

// Given two strings s and p, return an array of all the start indices of p's
// anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.

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

// We use a sliding window of size k, where k is length of p.
// Populate frequency array for p.
// Create a frequency array for s.
// for each element in s populate frequency array
// Process each window of size k
// cleanup from left side, append from right
// wherever maps match, add this to result
//
//
// Note that this solution also works for permutations!
// https://leetcode.com/problems/permutation-in-string/
// As long as we find one solution, result size > 0
// We have a solution!

#include <bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p) {
  // use the size of p as size of sliding window
  int m = s.size();
  int k = p.size();

  vector<int> res;

  // trying to check a bigger string for anagram
  if (k > m) {
    return res;
  }

  // mapping of string p to compare
  unordered_map<char, int> p_map;
  for (auto ch : p) {
    p_map[ch] += 1;
  }

  // also maintain a mapping of s, we will use this to compare
  unordered_map<char, int> s_map;

  int i = 0, j = 0;

  for (j = 0; j < k; j++) {
    s_map[s[j]] += 1;
  }

  // if these 2 maps are equal we have a result. we need the index i
  if (s_map == p_map) {
    res.push_back(i);
  }

  for (j = k; j < m; j++) {
    s_map[s[j]] += 1;

    // cleanup i
    s_map[s[i]] -= 1;

    if (s_map[s[i]] == 0) {
      s_map.erase(s[i]);
    }
    i += 1;

    // if these 2 maps are equal we have a result. we need the index i
    if (s_map == p_map) {
      res.push_back(i);
    }
  }
  return res;
}
