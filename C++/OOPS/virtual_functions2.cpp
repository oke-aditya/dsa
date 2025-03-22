// CPP program to illustrate
// working of Virtual Functions
// Explanation: Initially, we create a pointer
// of type base class and initialize it with the address
// of the derived class object. When we create an object of the
// derived class, the compiler creates a pointer as a
// data member of the class containing the address of VTABLE of the derived
// class.

#include <bits/stdc++.h>
using namespace std;

class Base {
 public:
  void fun1() { cout << "Base->1" << endl; }

  virtual void fun2() { cout << "Base->2" << endl; }

  virtual void fun3() { cout << "Base->3" << endl; }

  virtual void fun4() { cout << "Base->4" << endl; }
};

class Derived : public Base {
 public:
  void fun1() { cout << "Derived->1" << endl; }

  void fun2() { cout << "Derived->2" << endl; }
};

int main(int argc, char const* argv[]) {
  Base* base_ptr;
  Derived obj1;

  base_ptr = &obj1;

  // Early binding because fun1() is non-virtual
  // in base
  base_ptr->fun1();

  // Late Binding
  base_ptr->fun2();

  // Late Binding
  base_ptr->fun3();

  return 0;
}
