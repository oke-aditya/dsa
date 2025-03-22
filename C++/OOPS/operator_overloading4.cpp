// Overloading >> and << operators.

#include <bits/stdc++.h>

using namespace std;

class Complex {
 private:
  int real, img;

 public:
  Complex(int real = 0, int img = 0) {
    this->real = real;
    this->img = img;
  }

  friend ostream &operator<<(ostream &out, const Complex &c);
  friend istream &operator>>(istream &in, const Complex &c);
};

ostream &operator<<(ostream &out, const Complex &c) {
  out << c.real;
  out << "+ i" << c.img << endl;

  return out;
}

istream &operator>>(istream &in, const Complex &c) {
  cout << "Enter the real part";
  in >> c.real;

  cout << "enter the imag part";
  in >> c.img;

  return in;
}

int main(int argc, char const *argv[]) {
  Complex c1(10, 30);
  // cin>>c1;

  cout << "Complex object = " << endl;
  cout << c1;

  return 0;
}
