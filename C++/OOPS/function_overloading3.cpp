// If we want to overload a function of a base class, it is possible to unhide
// it by using the ‘using’ keyword. We can mitigate the problem as in 2.

#include <bits/stdc++.h>
using namespace std;

class Base {
 public:
  int fun() {
    cout << "Base::fun() called" << endl;
    return 0;
  }
};

class Derived : public Base {
 public:
  using Base::fun;

  // Note that this function will not be run.
  int fun(char c) {
    cout << "Derived::fun(char c) called" << endl;
    return 0;
  }
};

int main(int argc, char const *argv[]) {
  Derived d;
  auto res = d.fun();

  return 0;
}
