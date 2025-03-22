// Friend Class A friend class can access
// private and protected members of other class in which it is
// declared as friend. It is sometimes useful
// to allow a particular class to access private members of other class.
// a friend function can be given a special grant to access private and
// protected members.

// A friend function can be:
// a) A member of another class
// b) A global function

// Following are some important points about friend functions and classes:
// 1) Friends should be used only for limited purpose.
// too many functions or external classes are declared as friends of
// a class with protected or private data, it lessens the value of
// encapsulation of separate classes in object-oriented programming.
// 2) Friendship is not mutual. If class A is a friend of B,
// then B doesn’t become a friend of A automatically.
// 3) Friendship is not inherited (See this for more details)

#include <bits/stdc++.h>
using namespace std;

class B;

class A {
 public:
  void display(B &b_obj) { cout << "b = " << b_obj.x; }
};

class B {
 public:
  int x;

  // Constructor
  B() { x = 5; }
  friend void A ::display(B &b_obj);
};

int main(int argc, char const *argv[]) {
  A a;
  B x;
  a.display(x);

  return 0;
}
