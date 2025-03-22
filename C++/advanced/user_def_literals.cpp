// User Defined Literals (UDL) are added in C++ from C++11
// With UDL, we attach units to the values which has
// following advantages
// 1) The code becomes readable.
// 2) Conversion computations are done at compile time.
// weight = 2.3kg;
// ratio = 2.3kg/1.2lb

// he value of UDLs is substituted with the
// actual value defined in the code by the compiler at compile time.
// UDL’s don’t save much of coding time but more and
// more calculations can be shifted to compile-time for faster execution.

// UDLs are treated as a call to a literal operator.
// Only suffix form is supported.
// The name of the literal operator is operator “” followed by the suffix.
// Use long double to define dtypes.
// UDL can only work with the following parameters:
// char const*
// unsigned long long
// long double
// char const*, std::size_t
// wchar_t const*, std::size_t
// char16_t const*, std::size_t
// char32_t const*, std::size_t

// But return value can be of any types.
// We use _ to define literal operator suffixes.

#include <bits/stdc++.h>

#include <iostream>

using namespace std;

// User defined literals
// Here we assume x is dtype we pass.

// Kilograms
// We want to convert x kgs to gms.
long double operator"" _kg(long double x) { return (x * 1000); }

// Here we want to convert x gms to gms
// So we simply return.
long double operator"" _g(long double x) { return (x); }

// Here we want to convert x gms to mg

long double operator"" _mg(long double x) { return (x / 1000); }

int main(int argc, char const *argv[]) {
  long double weight = 3.6_kg;

  cout << weight << endl;
  cout << (weight + 2500.0_g) << endl;

  cout << (32.0_kg / 16000.0_g) << endl;

  return 0;
}
