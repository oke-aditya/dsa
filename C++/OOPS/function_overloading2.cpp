// Overloading doesn’t work for derived class in C++ programming language.
// There is no overload resolution between Base and Derived.
// The compiler looks into the scope of Derived, finds the single
// function “double f(double)” and calls it.
// It never disturbs with the (enclosing) scope of Base.
// In C++, there is no overloading across scopes
// – derived class scopes are not an exception to this general rule
// Even if the signature of the derived class method is
// different, all the overloaded methods in base class become hidden

#include<bits/stdc++.h>
using namespace std;

class Base
{
    public:
        int f(int i)
        {
            cout<<"int i = "<<i<<endl;
            return i;
        }
};

class Derived : public Base
{
    public:
        // Let's overload f. And typecast to double.
        int f(double i)
        {
            // Let's change i
            i = i + 3.2;
            cout<<"int i = "<<i<<endl;
            return i;
        }

        // We can solve this issue by following
        // using Base::f;

        // int f(double i);

};


int main(int argc, char const *argv[])
{
    Base ob1;
    Derived ob2, ob3;

    auto res = ob1.f(3);

    cout<<res<<endl;

    auto res2 = ob2.f(3.0);
    auto res3 = ob3.f(3);

    cout<<res2<<endl;

    cout<<res3<<endl;

    // Base class used it's own method
    // Derived class used it's own method.
    // When you declare a method in the subclass with the same name but a different signature,
    // it actually hides the version from the parent. 
    // Even though we passed int, it did not use base class method.

    return 0;
}

