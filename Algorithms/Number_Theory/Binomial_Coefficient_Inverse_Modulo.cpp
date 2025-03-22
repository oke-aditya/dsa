// Given q queries of type N, K calculate C(N, K) % P where P > N
// C is Combinatorial Coefficient

// If P < N we would have to use Lucas theorom.
// Otherwise this method works.

// C(N, K) = (N ! / K ! * (N - K) !)

// Under Modulo P conditions

// C(N, K) = (N ! % P) / ( (K ! % P) * ((N - K)!) % P)

// We will pre calculate N! % P. For 10 ** 6.

#include <algorithm>
#include <cmath>
#include <iostream>
#define P 1000000007
using namespace std;

int F[1000001];

int power(int a, int n) {
  int res = 1;
  while (n > 0) {
    if ((n % 2) == 1) {
      res = (res * 1LL * a) % P;
      n -= 1;
    } else {
      a = (a * 1LL * a) % P;
      n /= 2;
    }
  }
  return res;
}

int C(int n, int k) {
  if (k > n) {
    return 0;
  } else {
    // (N ! % P) Computed.
    int res = F[n];
    // Dividing with (K ! % P)
    // res = (res * inv(F[k]))
    res = (res * 1LL * power(F[k], P - 2)) % P;
    // Dividing with ((N - K)!) % P)
    res = (res * 1LL * power(F[n - k], P - 2)) % P;
    return res;
  }
}
int main() {
  F[0] = F[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    // F[i] = (F[i-1] * i) % P;
    // Note that the above expression might go out of integer range so we type
    // cast.
    F[i] = (F[i - 1] * 1LL * i) % P;
  }

  int q;
  int n, k;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    cout << C(n, k) << endl;
  }
}
