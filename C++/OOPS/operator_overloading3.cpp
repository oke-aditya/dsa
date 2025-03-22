// Operator overloading conversion operators
//
// Sometimes we might need to overloading typecasting operators
// to overload typecasting operators, we need to do following

#include <bits/stdc++.h>

#include <cmath>

using namespace std;

class Complex {
 private:
  double real, img;

 public:
  Complex(double real = 0.0, double img = 0.0) {
    this->real = real;
    this->img = img;
  }

  double mag() {
    return sqrt((this->real * this->real) + (this->img * this->img));
  }

  operator double() { return mag(); }
};

int main(int argc, char const *argv[]) {
  Complex c1 = Complex(8, 6);
  double c2 = (double)c1;
  cout << c2;
  return 0;
}
