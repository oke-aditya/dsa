// In C++, we can make operators to work for user defined classes.
// This means C++ has the ability
// to provide the operators with a special meaning for a data type,
// this ability is known as operator overloading.

#include <bits/stdc++.h>

using namespace std;

class Complex
{
private:
    int real, img;

public:
    Complex(int real = 0, int img = 0)
    {
        this->real = real;
        this->img = img;
    }

    // Overloaded operator must have either zero or one argument
    Complex operator + (Complex const &c2)
    {
        Complex res;
        res.real = this->real + c2.real;
        res.img = this->img + c2.img;

        return res;
    }


    void print()
    {
        cout<<this->real<<" "<<this->img<<"i"<<endl;
    }

};

// We cannot overload
//    . (dot) 
//    :: 
//    ?: 
//    sizeof 

int main(int argc, char const *argv[])
{
    Complex c1(10, 2);
    Complex c2(10, 3);

    auto res = c1 + c2;

    res.print();

    return 0;
}
