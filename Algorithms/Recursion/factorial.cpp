// Find factorial of number using recursion

#include <bits/stdc++.h>
using namespace std;

int fact_rec(int n) {
  if (n == 1) {
    return 1;
  } else {
    return (n * fact_rec(n - 1));
  }
}

int fact_itr(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res *= i;
  }
  return res;
}

int main(int argc, char const *argv[]) {
  int n = 4;
  auto res = fact_rec(n);
  auto res2 = fact_itr(n);
  cout << res << endl;
  cout << res2 << endl;

  return 0;
}
