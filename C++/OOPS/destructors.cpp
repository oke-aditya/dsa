// Destructor is a member function which destructs or deletes an object.
// It is usually called automatically.
// Destructor function is automatically invoked when the objects are destroyed.
// It cannot be declared static or const.
// The destructor does not have arguments.
// It has no return type not even void.
// An object of a class with a Destructor cannot become a member of the union.
// A destructor should be declared in the public section of the class.
// The programmer cannot access the address of destructor.

// (1) the function ends
// (2) the program ends
// (3) a block containing local variables ends
// (4) a delete operator is called

#include <bits/stdc++.h>
using namespace std;

class cons2 {
 public:
  int x, y;

  cons2() {
    this->x = x;
    this->y = y;
  }

  // Destructor.
  ~cons2();
};

int main(int argc, char const *argv[]) {
  cons2 a;

  return 0;
}
