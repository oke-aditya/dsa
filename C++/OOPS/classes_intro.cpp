// Simple example for class

#include <bits/stdc++.h>

class Simple {
  // Decalre data members
 public:
  int fees;
  std::string name;

  // Declare member functions
  // Leave for outside

  void print_fees();

  // Declare inside.
  void print_name() { std::cout << this->name << std::endl; }

  // End the class with ;
};

void Simple::print_fees() {
  // Continue same function
  std::cout << this->fees << std::endl;
}

int main(int argc, char const *argv[]) {
  // Create an object
  Simple obj;

  obj.name = "Me";
  obj.fees = 100;
  obj.print_name();
  obj.print_fees();

  return 0;
}
