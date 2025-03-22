// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Given a string S of lowercase letters,
// a duplicate removal consists of choosing two adjacent and equal letters, and
// removing them.

// We repeatedly make duplicate removals on S until we no longer can.

// Return the final string after all such duplicate removals have been made.  It
// is guaranteed the answer is unique.

// Input: "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb"
// since the letters are adjacent and equal, and this is the only possible move.
// The result of this move is that the string is "aaca", of which only "aa" is
// possible, so the final string is "ca".

#include <bits/stdc++.h>
using namespace std;

string remove_adj(string s) {
  stack<char> stk;
  string res = "";

  for (char ch : s) {
    if (stk.empty())
      stk.push(ch);

    else {
      char chk = stk.top();

      if (chk != ch)
        stk.push(ch);

      else
        stk.pop();
    }
  }

  while (!stk.empty()) {
    res += stk.top();
    stk.pop();
  }

  reverse(res.begin(), res.end());

  return res;
}

int main(int argc, char const *argv[]) {
  string s = "abbaca";
  auto res = remove_adj(s);

  cout << res << endl;

  return 0;
}
