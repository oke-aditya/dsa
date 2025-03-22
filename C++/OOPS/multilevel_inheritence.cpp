// Simple example for multi-level inheritence.
// Vehicle
//  |
//  |
//  Fourwheeler
//  |
//  |
//  Car
//
//

#include <bits/stdc++.h>
using namespace std;

class Vehicle {
 public:
  Vehicle() {
    cout << "This is a vehicle. Constructor called for Vehicle " << endl;
  }
};

class FourWheeler : public Vehicle {
 public:
  FourWheeler() {
    cout << "This is FourWheeler. Constructor called Fourwheeler " << endl;
  }
};

class Car : public FourWheeler {
 public:
  Car() { cout << "This is Car. Constructor called for Car" << endl; }
};

int main(int argc, char const *argv[]) {
  Car obj;

  return 0;
}
