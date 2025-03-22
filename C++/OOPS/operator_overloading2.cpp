// Example to overload ++ operator.

#include <bits/stdc++.h>

using namespace std;

class Overload_inc {
 private:
  int count;

 public:
  Overload_inc() { this->count = 4; }

  // Overloading recieves either 0 or 1 arg.
  // This overload ++i . Pre-increment operator.
  void operator++() { this->count += 2; }

  // Overloading the i++. Post-increment operator.
  //

  void operator++(int) { this->count += 2; }

  void display() { cout << "Count = " << this->count << endl; }
};

int main(int argc, char const *argv[]) {
  Overload_inc i;
  ++i;
  i.display();

  i++;
  i.display();

  return 0;
}
