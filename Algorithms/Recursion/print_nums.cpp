// print numbers 1 to n and n to 1 using recursion

#include <bits/stdc++.h>
using namespace std;

void print_to_n(int n) {
  if (n == 1) {
    cout << n << " ";
    return;
  }
  print_to_n(n - 1);
  cout << n << " ";
}

void print_n_to(int n) {
  if (n == 1) {
    cout << n << " ";
    return;
  }
  cout << n << " ";
  print_n_to(n - 1);
}

int main(int argc, char const *argv[]) {
  int n = 4;
  print_to_n(n);
  cout << endl;
  print_n_to(n);
  cout << endl;
  return 0;
}
