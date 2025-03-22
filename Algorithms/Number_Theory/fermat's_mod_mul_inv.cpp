#include <iostream>
using namespace std;

int power(int a, int n, int m) {
  // Bianry exponentiation to get the power and modulo
  int result = 1;
  while (n > 0) {
    if (n % 2 == 0) {
      // n is even
      a = (a * a) % m;
      n /= 2;
    } else {
      // n is odd.
      result = (result * a) % m;
      n -= 1;
    }
  }
  return result;
}

int main() {
  // Time complexity = O(log(m))
  int a, b, m;
  cin >> a >> m;
  cout << endl << "a^-1 = " << power(a, m - 2, m);
  return (0);
}