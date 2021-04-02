// C++ program to demonstrate working of
// inline namespaces
// An inline namespace is a namespace that uses the optional
// keyword inline in its original-namespace-definition.

#include <iostream>
using namespace std;

namespace ns1
{
    inline namespace ns2
    {
        int var = 10;
    }
}

int main()
{
    cout << ns1::var;
    return 0;
}
