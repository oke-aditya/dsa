// Simple example for try and catch block

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int x = -1;
  cout << endl << "Before try";

  try {
    cout << endl << "Inside try";
    if (x < 0) {
      throw x;
      cout << "This will not be printed" << endl;
    }
  }

  catch (int x) {
    cout << endl << "Exception Caught";
  }

  cout << endl << "After catch. Stuff will be continued";
  cout << endl;

  return (0);
}
