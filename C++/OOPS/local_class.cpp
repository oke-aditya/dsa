// A class declared inside a function becomes local to that function and is called Local Class
// A local class type name can only be used in the enclosing function.

#include<bits/stdc++.h>

using namespace std;

void fun()
{
    class Test
    {

    };

    // We can declare objects from local class.
    // In function
    Test t;
    Test *tp;
}


// All the methods of Local classes must be defined inside the class only.

void fun2()
{
    class Test2
    {
        void display()
        {
            cout<<"Hello from here";
        }
    };

    // We cannot use :: and declare it from outside.
}

// A  Local class cannot contain static data members. It may contain static functions though.


// Member methods of local class can only access static
// and enum variables of the enclosing function.
// Non-static variables of the enclosing function are not accessible inside local classes


int main(int argc, char const *argv[])
{
    // But we cannot use them outside.
    // Test t1;

    return 0;
}

