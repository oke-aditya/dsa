// Simple single inheritence in C++

#include <bits/stdc++.h>
using namespace std;

class Vehicle {
 protected:
  int length, breadth, height;

 public:
  Vehicle(int length, int breadth, int height) {
    this->length = length;
    this->breadth = breadth;
    this->height = height;
  }

 public:
  void show_details() {
    cout << endl
         << "Details of car: " << this->length << " " << this->breadth << " "
         << this->height << " ";
  }
};

class Car : protected Vehicle {
  // All these above methods are inherited.
  // Let's add an exta name
 public:
  string name;

 public:
  // We need to call the super() constructor.
  Car(string name, int length, int breadth, int height)
      : Vehicle(length, breadth, height) {
    this->name = name;
  }

 public:
  void show_details() {
    cout << endl
         << "Details of car: " << this->length << " " << this->breadth << " "
         << this->height << " " << this->name;
  }
};

int main(int argc, char const *argv[]) {
  Vehicle v1(12, 20, 30);
  Car c1("bmw", 22, 30, 40);

  v1.show_details();
  c1.show_details();

  cout << endl;

  return 0;
}
