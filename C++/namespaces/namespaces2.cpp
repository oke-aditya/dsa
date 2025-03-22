// Namespace declarations appear only at global scope.
// Namespace declarations can be nested within another namespace.
// Namespace declarations don’t have access specifiers. (Public or private)
// No need to give semicolon after the closing brace of definition of namespace.
// We can split the definition of namespace over several units.

#include <bits/stdc++.h>

using namespace std;

namespace ns1 {
int value() { return 5; }
}  // namespace ns1

namespace ns2 {
const double x = 200;
double value() { return (2 * x); }

}  // namespace ns2

int main(int argc, char const *argv[]) {
  cout << ns1::value() << endl;
  cout << ns2::value() << endl;

  // We can also access the variable
  cout << ns2::x << endl;

  return 0;
}
