// This pointer.
// This poiner is used in following cases.

#include <bits/stdc++.h>
using namespace std;

// 1. Constructors in classes.
// This points to the object of class.
// Use this in constructors to allocate data.

// 2. To return the object passed in class.
// We can simply return *this. (ris)

class Simple {
 private:
  int x;

 public:
  // A constrcutor.
  // Constructor can use this, to assign data.
  Simple(int x) { this->x = x; }

  // Member function can use this to acces objects's details.
  void print() { cout << endl << "Value of x = " << this->x; }

  // Function that returns object.
  Simple return_obj() { return *this; }
};

int main(int argc, char const *argv[]) {
  Simple obj(12);
  obj.print();

  // We get the object back using ris.
  Simple ret = obj.return_obj();

  ret.print();

  cout << endl;

  return 0;
}
