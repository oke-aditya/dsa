// Given n pairs of parentheses, write a function
// to generate all combinations of well-formed parentheses of length 2*n.
// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"

#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void print_v(vector<string> v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

void solve(int open, int close, string op) {
  if (open == 0 && close == 0) {
    // cout<<op<<" ";
    res.push_back(op);
    return;
  }
  if (open != 0) {
    op += "(";
    solve(open - 1, close, op);
  }
  if (close > open) {
    op += ")";
    solve(open, close - 1, op);
  }
  return;
}

void generate_paran(int n) {
  int close = n;
  int open = n;
  string op = "";
  solve(open, close, op);
}

int main(int argc, char const *argv[]) {
  int n = 3;
  generate_paran(n);
  print_v(res);

  return 0;
}
