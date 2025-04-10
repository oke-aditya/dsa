// https://leetcode.com/problems/backspace-string-compare/
// Given two strings s and t, return true if they are equal when both are 
// typed into empty text editors. '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty. 

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".



#include <bits/stdc++.h>

using namespace std;

string process_str(stack<char> &stk, string s) {
  for (auto ch : s) {
    if (ch == '#') {
      if (!stk.empty()) {
        stk.pop();
      }
    }

    else {
      stk.push(ch);
    }
  }

  string res = "";
  while (!stk.empty()) {
    res += stk.top();
    stk.pop();
  }

  return res;
}

bool backspaceCompare(string s, string t) {
  stack<char> stk1;
  stack<char> stk2;

  string res1 = process_str(stk1, s);
  string res2 = process_str(stk2, t);

  return res1 == res2;
}