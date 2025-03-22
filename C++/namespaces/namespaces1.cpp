// In each scope, a name can only represent one entity.
// Using namespaces, we can create two variables or member functions having the
// same name

#include <bits/stdc++.h>
using namespace std;

// Variable in a namespace
namespace first {
int val = 100;
}

// A global variable.
int val = 200;

int main(int argc, char const *argv[]) {
  int val = 300;

  // Variable within the namespace
  cout << first::val << endl;

  // Local variable (as it is prefered over global)
  cout << val << endl;

  return 0;
}

// Namespaces allow us to group named entities that otherwise
// would have global scope into narrower scopes, giving them namespace scope.
// This allows organizing the elements of programs into different logical scopes
// referred to by names. A namespace is a declarative region that provides/ a
// scope to the identifiers (names of the types, function, variables etc) inside
// it. Multiple namespace blocks with the same name are allowed.
