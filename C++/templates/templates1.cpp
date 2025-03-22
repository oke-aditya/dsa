// Templates are expanded at compiler time.
// This is like macros. The difference is, compiler does type checking before
// template expansion. The idea is simple, source code contains only
// function/class, but compiled code may contain multiple copies of same
// function/class.

//  It eliminates the need to create different
// algorithms if the data type is an integer, string or a character.

// The advantages of Generic Programming are

//     Code Reusability
//     Avoid Function Overloading
//     Once written it can be used for multiple times and cases.

#include <bits/stdc++.h>
using namespace std;

// Generic function using template.

template <typename T>
T newMax(T x, T y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}

int main(int argc, char const *argv[]) {
  cout << newMax<int>(3, 4) << endl;
  cout << newMax<double>(3.2, 4.2) << endl;
  cout << newMax<char>('g', 'e') << endl;

  return 0;
}
