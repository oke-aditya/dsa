// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

// Given two strings s and part, perform the following operation on s until all
// occurrences of the substring part are removed: Find the leftmost occurrence
// of the substring part and remove it from s. Return s after removing all
// occurrences of part. A substring is a contiguous sequence of characters in a
// string.

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".

// Solution
// Trick here is to simply accept a O(m * n) stack solution.
// this can't be done in one pass easily.
// just check if stk end characters are good enough after we have reached part
// size.

#include <bits/stdc++.h>
using namespace std;

bool check_match(stack<char> stk, string part, int n) {
  for (int j = n - 1; j >= 0; j--) {
    // cout<<stk.top()<<" ";
    // cout<<part[j];
    if (stk.top() != part[j]) {
      return false;
    } else {
      stk.pop();
    }
  }
  return true;
}

string removeOccurrences(string s, string part) {
  stack<char> stk;
  int i = 0, j = 0, k = 0;
  string curr_str = "";
  int m = s.size();
  int n = part.size();
  string res;

  for (i = 0; i < m; i++) {
    stk.push(s[i]);
    if (stk.size() >= n && check_match(stk, part, n)) {
      for (int z = 0; z < n; z++) {
        stk.pop();
      }
    }
  }

  while (!stk.empty()) {
    res += stk.top();
    stk.pop();
  }

  reverse(begin(res), end(res));
  return res;
}
