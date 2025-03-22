// Given a string S, we can transform every letter individually to
// be lowercase or uppercase to create another string.
// Return a list of all possible strings we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]

// Solution: -
// We have 2 choices if the character is letter, it can be converted to upper
// case or lower case. If the character is digit we have no choice, we just take
// it. We just add these to results.

#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void print_v(vector<string> v) {
  for (auto x : v) {
    cout << x << " ";
  }
}

void solve(string inp, string op) {
  if (inp.length() == 0) {
    res.push_back(op);
    return;
  }

  if (isalpha(inp[0])) {
    string op1 = op;
    string op2 = op;
    op1 += tolower(inp[0]);
    op2 += toupper(inp[0]);
    inp.erase(inp.begin() + 0);
    solve(inp, op1);
    solve(inp, op2);
  } else {
    // It's a digit so we have only one choice
    string op1 = op;
    op1 += inp[0];
    inp.erase(inp.begin() + 0);
    solve(inp, op1);
  }
}

vector<string> perm_letter_case(string str) {
  string inp = str;
  string op = "";

  solve(inp, op);
  return res;
}

int main(int argc, char const *argv[]) {
  string str = "a1b2";
  auto res = perm_letter_case(str);
  print_v(res);
  cout << endl;
  return 0;
}
