// Problem with Normal pointer
// A pointer points to object / variable.
// They are not de allocated automatically.
// We need to free() them.
// Memory leak can occur.
// Smart pointer can avoid these issues.

#include <bits/stdc++.h>
using namespace std;

class Rectangle {
 private:
  int length, breadth;
};

void fun() {
  // Create a pointer to rectangle
  Rectangle *rp = new Rectangle();
}

int main(int argc, char const *argv[]) {
  while (true) {
    fun();
  }
  return 0;
}

// In above example
// Once the function ends this ‘p’ is deleted because p is a local variable to
// the function but a new rectangle that is allocated inside heap that will not
// be deallocated We will soon be occupying the heap memory space, through
// infinte loops. We need to explicitly delete the pointer.

// Smart pointers
// Smart pointers are automatically de-allocated when they are not needed.
// Heap memory is automatically retained.
// Smart pointers are already in C++ std lib and we can use them.
