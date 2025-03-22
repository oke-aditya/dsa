// // https://leetcode.com/problems/repeated-dna-sequences/

// The DNA sequence is composed of a series of nucleotides abbreviated as 'A',
// 'C', 'G', and 'T'. For example, "ACGAATTCCG" is a DNA sequence. Given a
// string s that represents a DNA sequence, return all the 10-letter-long
// sequences (substrings) that occur more than once in a DNA molecule. You may
// return the answer in any order.

// Example 1:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC","CCCCCAAAAA"]

// Example 2:

// Input: s = "AAAAAAAAAAAAA"
// Output: ["AAAAAAAAAA"]

// We keep the characters of length 10 in a map.
// Check if that map has got items more than once.
// Push those to result
//

#include <bits/stdc++.h>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
  int k = 10;
  int n = s.size();

  vector<string> res;

  // process each string and save 10 length stuff in map?
  // or store it in set?
  // then check if it exists?

  int j = 0;
  string curr_dna = "";

  for (j = 0; j < k; j++) {
    curr_dna += s[j];
  }

  unordered_map<string, int> mp;
  mp[curr_dna] += 1;

  int i = 0;
  for (j = k; j < n; j++) {
    curr_dna.erase(0, 1);
    curr_dna += s[j];
    mp[curr_dna] += 1;
  }

  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    if (itr->second > 1) {
      res.push_back(itr->first);
    }
  }

  return res;
}
