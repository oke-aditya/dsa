// Function overloading is a feature in C++ where two or more functions can have the same name but different parameters.
// When a function name is overloaded with different jobs it is called Function Overloading.
// In Function Overloading “Function” name should be the same and the arguments should be different.
// Function overloading can be considered as an example of polymorphism feature in C++.

// If a not exact match is found:–

// ->Char, Unsigned char, and short are promoted to an int.

// ->Float is promoted to double

// If no match found:

// ->C++ tries to find a match through the standard conversion.

// Else: 

// Error :(

#include<bits/stdc++.h>

using namespace std;

void print_stuff(int i)
{
    cout<<"int i = "<<i<<endl;
}

void print_stuff(double i)
{
    cout<<"double i = "<<i<<endl;
}

void print_stuff(string i)
{
    cout<<"string i = "<<i<<endl;
}

// Functions that cannot be overloaded
// Function declarations that differ only in the return type.
// Member function declarations with the same name and the
// name parameter-type-list cannot be overloaded if any of them is a static member function declaration
// Parameter declarations that differ only in
// a pointer * versus an array [] are equivalent.
// That is, the array declaration is adjusted to become a pointer declaration

// Parameter declarations that differ only in the presence or absence
// of const and/or volatile are equivalent. That is, the const and
// volatile type-specifiers for each parameter type are ignored
// when determining which function is being declared, defined, or called.


int main(int argc, char const *argv[])
{
    int x = 1;
    double y = 2;
    string name = "oke";

    print_stuff(x);
    print_stuff(y);
    print_stuff(name);

    return 0;
}
