// Given a positive integer N, the task is to find all
// the N bit binary numbers having more than or
// equal 1’s than 0’s for any prefix of the number.

// Input:  N = 2
// Output: 11 10
// Explanation: 11 and 10 have more than
// or equal 1's than 0's

// Input:  N = 3
// Output: 111 110 101
// Explanation: 111, 110 and 101 have more
// than or equal 1's than 0's

#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void print_v(vector<string> v) {
  for (auto x : v) {
    cout << x << " ";
  }
}

void solve(int one, int zero, int n, string op) {
  if (n == 0) {
    res.push_back(op);
    return;
  }
  string op1 = op;
  op1 += "1";
  solve(one + 1, zero, n - 1, op1);

  if (one > zero) {
    string op2 = op;
    op2 += "0";
    solve(one, zero + 1, n - 1, op2);
  }
  return;
}

void nbit_nos(int n) {
  int one = 0;
  int zero = 0;
  string op = "";
  solve(one, zero, n, op);
}

int main(int argc, char const *argv[]) {
  int n = 3;
  nbit_nos(n);
  print_v(res);
  cout << endl;
  return 0;
}
