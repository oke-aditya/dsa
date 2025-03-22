// Simple Multiple inheritence in C++
// Vehicle           FourWheeler
//      ---  Car -----
//
//

#include <bits/stdc++.h>
using namespace std;

class Vehicle {
 public:
  Vehicle() {
    cout << "This is vehicle, Constructor for Vehicle is called. " << endl;
  }
};

class FourWheeler {
 public:
  FourWheeler() {
    cout << "This is a FourWheeler, Constructor for Fourwheeler called "
         << endl;
  }
};

class Car : public Vehicle, public FourWheeler {
 public:
  Car() { cout << "This is Car, Construcotr for car is called" << endl; }
};

int main(int argc, char const *argv[]) {
  Car obj;
  return 0;
}
