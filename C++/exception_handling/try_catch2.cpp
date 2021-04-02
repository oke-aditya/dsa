// C++ library has a standard exception class which is base class for all standard exceptions.
// All objects thrown by components of the standard library are derived from this class.
// Therefore, all standard exceptions can be caught by catching this type
// C++, all exceptions are unchecked. Compiler doesn’t check whether an exception is caught or not.
// For example, in C++, it is not necessary to specify all uncaught exceptions in a function declaration.


#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    try
    {
        throw 10;
    }

    catch (char *excp)
    {
        cout<<"Caught"<<endl;
    }

    // Use catch(...) to catch all remaining errors.
    catch(...)
    {
        cout<<"Default Exception"<<endl;
    }

    return 0;
}
