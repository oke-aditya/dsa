// https://leetcode.com/problems/backspace-string-compare/

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