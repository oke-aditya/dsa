// https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

// You are given a 0-indexed array of strings words and a 2D array of integers
// queries.

// Each query queries[i] = [li, ri] asks us to find the number of strings
// present in the range li to ri (both inclusive) of words that start and end
// with a vowel. Return an array ans of size queries.length, where ans[i] is the
// answer to the ith query. Note that the vowel letters are 'a', 'e', 'i', 'o',
// and 'u'.

#include <bits/stdc++.h>

using namespace std;

bool is_start_end_vowel(string s) {
  vector<string> vowels = {"a", "e", "i", "o", "u"};
  string chk = string{s[0]};
  string chk2 = string{s[s.size() - 1]};

  bool first_check = false;
  bool last_check = false;

  for (auto v : vowels) {
    if (v == chk) {
      first_check = true;
    }
    if (v == chk2) {
      last_check = true;
    }
  }

  return (first_check && last_check);
}

vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
  vector<int> res;
  int n = words.size();
  vector<int> prefix_count(n + 1);

  for (int i = 0; i < n; i++) {
    if (is_start_end_vowel(words[i])) {
      prefix_count[i + 1] = prefix_count[i] + 1;
    } else {
      prefix_count[i + 1] = prefix_count[i];
    }
  }

  for (auto q : queries) {
    int left = q[0];
    int right = q[1];

    res.push_back(prefix_count[right + 1] - prefix_count[left]);
  }

  // for(auto c: prefix_count)
  // {
  //     cout<<c<<" ";
  // }

  return res;
}
