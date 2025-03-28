// https://leetcode.com/problems/first-unique-character-in-a-string/

// Given a string s, return the first non-repeating character in it
// and return its index. If it does not exist, return -1.

// Store the

#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
  map<char, int> mp;
  for (int i = 0; i < s.length(); i++) {
    mp[s[i]]++;
  }

  for (int i = 0; i < s.length(); i++) {
    // Appeared only once so didn't repeat.
    if (mp[s[i]] == 1) {
      return i;
    }
  }

  return -1;
}
