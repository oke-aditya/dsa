// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

// Generalize it for k.

// A string is good if there are no repeated characters.

// Given a string s​​​​​, return the number of good substrings of
// length three in s​​​​​​.

// Note that if there are multiple occurrences of the same substring, every
// occurrence should be counted.

// A substring is a contiguous sequence of characters in a string.

// Example 1:

// Input: s = "xyzzaz"
// Output: 1
// Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and
// "zaz". The only good substring of length 3 is "xyz".

// Example 2:

// Input: s = "aababcabc"
// Output: 4
// Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc",
// "bca", "cab", and "abc". The good substrings are "abc", "bca", "cab", and
// "abc".

// solution:
// process the first sub array, find if the map size == k
// for subsequent reduce the count in map, erase if 0
// add the new index to map.
// if map.size() == k. increment the count
// return the count.

#include <bits/stdc++.h>

using namespace std;

int subsdistinct(string s, int k) {
  map<char, int> mp;
  int j = 0;
  int count = 0;
  int k = 3;
  int n = s.size();

  for (j = 0; j < k; j++) {
    mp[s[j]] += 1;

    if (mp.size() == k) {
      count += 1;
    }
  }

  int i = 0;

  for (j = k; j < n; j++) {
    mp[s[i]] -= 1;

    if (mp[s[i]] == 0) {
      mp.erase(s[i]);
    }

    i += 1;
    mp[s[j]] += 1;

    // cout<<mp.size()<<endl;

    // now check the size
    if (mp.size() == k) {
      count += 1;
    }
  }

  return count;
}