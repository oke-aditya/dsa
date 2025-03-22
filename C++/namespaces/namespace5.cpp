// Using namespace in header files

// Use "" to include local header files
#include <iostream>

#include "simple_header.h"

int main(int argc, char const *argv[]) {
  std::cout << foo::value() << std::endl;
  return 0;
}
