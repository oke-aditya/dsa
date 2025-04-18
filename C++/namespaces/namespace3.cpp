// Unnamed Namespaces

// They are directly usable in the same program and are used for declaring
// unique identifiers. In unnamed namespaces, name of the namespace in not
// mentioned in the declaration of namespace. The name of the namespace is
// uniquely generated by the compiler. The unnamed namespaces you have created
// will only be accessible within the file you created it in. Unnamed namespaces
// are the replacement for the static declaration of variables.

// C++ program to demonstrate working of unnamed
// namespaces
#include <iostream>
using namespace std;

// unnamed namespace declaration
namespace {
int rel = 300;
}

int main() {
  cout << rel << "\n";  // prints 300
  return 0;
}
