// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent. Return the answer in any
// order.

// A mapping of digits to letters (just like on the telephone buttons) is given
// below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

#include <bits/stdc++.h>
using namespace std;

void print_vs(vector<string> vv) {
  for (auto s : vv) {
    cout << s << ", ";
  }
}

void backtrack(string digits, int start, string &sol, vector<string> &res,
               vector<string> mapping) {
  // if we have explored all the digits
  if (start == digits.size()) {
    res.push_back(sol);
    return;
  }

  // We know this mapping
  // We need to pick based on this mapping
  for (char &ch : mapping[digits[start] - '2']) {
    sol += ch;
    backtrack(digits, start + 1, sol, res, mapping);
    sol.pop_back();
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> res;
  string sol;
  vector<string> mapping = {"abc", "def",  "ghi", "jkl",
                            "mno", "pqrs", "tuv", "wxyz"};

  int start = 0;
  if (digits.size() > 0) backtrack(digits, start, sol, res, mapping);

  return res;
}

int main(int argc, char const *argv[]) {
  string digits = "23";
  auto res = letterCombinations(digits);
  print_vs(res);

  return 0;
}
