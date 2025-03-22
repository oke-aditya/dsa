// Given a boolean expression with following symbols.
// 'T' ---> true
// 'F' ---> false

// And following operators filled between symbols
// Operators
// &   ---> boolean AND
// |   ---> boolean OR
// ^   ---> boolean XOR

// Count the number of ways we can parenthesize the expression so that the value
// of expression evaluates to true.

// Input: symbol[]    = {T, F, T}
//        operator[]  = {^, &}
// Output: 2
// The given expression is "T ^ F & T", it evaluates true
// in two ways "((T ^ F) & T)" and "(T ^ (F & T))"

// Input: symbol[]    = {T, F, F}
//        operator[]  = {^, |}
// Output: 2
// The given expression is "T ^ F | F", it evaluates true
// in two ways "( (T ^ F) | F )" and "( T ^ (F | F) )".

// Input: symbol[]    = {T, T, F, T}
//        operator[]  = {|, &, ^}
// Output: 4
// The given expression is "T | T & F ^ T", it evaluates true
// in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
// and (T|((T&F)^T)).

#include <bits/stdc++.h>
using namespace std;

int paranthesis_count_rec(string s, int i, int j, int is_true) {
  if (i > j) {
    return 0;
  }
  if (i == j) {
    if (is_true) {
      return s[i] == 'T';
    } else {
      return s[i] == 'F';
    }
  }
  int ans = 0;
  for (int k = i + 1; k < j; k = k + 2) {
    int leftF, leftT, rightF, rightT;

    leftT = paranthesis_count_rec(s, i, k - 1, 1);
    rightT = paranthesis_count_rec(s, k + 1, j, 1);
    leftF = paranthesis_count_rec(s, i, k - 1, 0);
    rightF = paranthesis_count_rec(s, k + 1, j, 0);

    if (s[k] == '&') {
      if (is_true) {
        ans += leftT * rightT;
      } else {
        ans += leftF * rightF + leftT * rightF + leftF * rightT;
      }
    } else if (s[k] == '|') {
      if (is_true) {
        ans += leftT * rightT + leftT * rightF + leftF * rightT;
      } else {
        ans += leftF * rightF;
      }

    } else if (s[k] == '^') {
      if (is_true) {
        ans += leftF * rightT + leftT * rightF;
      } else {
        ans += leftT * rightT + leftF * rightF;
      }
    }
  }
  return ans;
}

int dp[100][100][3];

int paranthesis_count_mem(string s, int i, int j, int is_true) {
  if (i > j) {
    return 0;
  }
  if (i == j) {
    if (is_true) {
      return s[i] == 'T';
    } else {
      return s[i] == 'F';
    }
  }
  if (dp[i][j][is_true] != -1) {
    return (dp[i][j][is_true]);
  }
  int ans = 0;
  for (int k = i + 1; k < j; k += 2) {
    int leftF, leftT, rightF, rightT;
    if (dp[i][k - 1][1] != -1) {
      return dp[i][k - 1][1];
    } else {
      leftT = paranthesis_count_mem(s, i, k - 1, 1);
    }
    if (dp[k + 1][j][1] != -1) {
      return dp[k + 1][j][1];
    } else {
      rightT = paranthesis_count_mem(s, k + 1, j, 1);
    }
    if (dp[i][k - 1][0] != -1) {
      return dp[i][k - 1][0];
    } else {
      leftF = paranthesis_count_mem(s, i, k - 1, 0);
    }
    if (dp[k + 1][j][0] != -1) {
      return dp[k + 1][j][0];
    } else {
      rightF = paranthesis_count_mem(s, k + 1, j, 0);
    }

    if (s[k] == '&') {
      if (is_true) {
        ans += leftT * rightT;
      } else {
        ans += leftF * rightF + leftT * rightF + leftF * rightT;
      }
    } else if (s[k] == '|') {
      if (is_true) {
        ans += leftT * rightT + leftT * rightF + leftF * rightT;
      } else {
        ans += leftF * rightF;
      }

    } else if (s[k] == '^') {
      if (is_true) {
        ans += leftF * rightT + leftT * rightF;
      } else {
        ans += leftT * rightT + leftF * rightF;
      }
    }
    dp[i][j][is_true] = ans;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  string symbols = "TTFT";
  string operators = "|&^";
  string s;
  int j = 0;

  for (int i = 0; i < symbols.length(); i++) {
    s.push_back(symbols[i]);
    if (j < operators.length()) s.push_back(operators[j++]);
  }

  // We obtain the string  T|T&F^T
  int n = s.length();

  // There are 4 ways
  // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
  // (T|((T&F)^T))

  cout << paranthesis_count_rec(s, 0, n - 1, 1) << endl;
  cout << paranthesis_count_mem(s, 0, n - 1, 1) << endl;
  memset(dp, -1, sizeof(dp));

  return 0;
}
