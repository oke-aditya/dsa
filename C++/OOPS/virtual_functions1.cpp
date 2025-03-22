// A virtual function is a member function which is declared
// in the base class using the keyword virtual and is
// re-defined (Overriden) by the derived class.

// When you refer to a derived class object using a pointer or a
// reference to the base class, you can call a virtual function for
// that object and execute the derived class’s version of the function.

// Virtual functions ensure that the correct function is called
// for an object, regardless of the type of reference (or pointer) used for
// function call. They are mainly used to achieve Runtime polymorphism Functions
// are declared with a virtual keyword in base class. The resolving of function
// call is done at Run-time.

// Virtual functions cannot be static.
// A virtual function can be a friend function of another class.
// Virtual functions should be accessed using pointer or reference of base class
// type to achieve run time polymorphism.
// The prototype of virtual functions should be the same in the base as well as
// derived class. They are always defined in the base class and overridden in a
// derived class. It is not mandatory for the derived class to override (or
// re-define the virtual function), in that case, the base class version of the
// function is used. A class may have virtual destructor but it cannot have a
// virtual constructor.

// E.g. of virtual function

#include <bits/stdc++.h>
using namespace std;

class Base {
 public:
  virtual void print() { cout << "Print of base class is called" << endl; }

  void show() { cout << "Show base class is called" << endl; }
};

class Derived : public Base {
 public:
  void print() { cout << "Print of Derived class is called" << endl; }

  void show() { cout << "Show of derived class is called" << endl; }
};

int main(int argc, char const *argv[]) {
  // A base pointer.
  Base *bptr;

  // A derived object.
  Derived d;

  // Pointing the base pointer to the derived object.
  bptr = &d;

  // Calling the virutal function.
  // Binding at the run time
  bptr->print();

  // Non virtual function.
  // Binding at the compile time
  bptr->show();

  return 0;
}

// Runtime polymorphism is
// achieved only through a pointer (or reference)
// of base class type. Also, a base class pointer can
// point to the objects of base class as well as to the objects of?
// derived class. In above code, base class pointer ‘bptr’ contains
// the address of object ‘d’ of derived class.

// Created a virtual function in the base class and it is being overridden
// in the derived class then we don’t need virtual keyword in the derived
// class, functions are automatically considered as virtual functions
// in the derived class.

// If object of that class is created then a virtual pointer(VPTR)
// is inserted as a data member of the class to point to VTABLE of that class.
// For each new object created,
// a new virtual pointer is inserted as a data member of that class.
// Irrespective of object is created or not, a static array of
// function pointer called VTABLE where each cell contains the
// address of each virtual function contained in that class.
