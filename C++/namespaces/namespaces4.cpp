// Classes and Namespace:

// Following is a simple way to create classes in a name space

// Class can also be declared inside namespace and defined outside namespace

#include <iostream>
using namespace std;

namespace ns1 {
class Simple {
 public:
  void display() { cout << "Hello from simple" << endl; }
};
}  // namespace ns1

namespace ns2 {
class Complic;
}

class ns2 ::Complic {
 public:
  void display() { cout << "Hi from Complic" << endl; }
};

int main(int argc, char const *argv[]) {
  ns1::Simple obj;
  obj.display();

  ns2::Complic obj2;
  obj2.display();

  return 0;
}
