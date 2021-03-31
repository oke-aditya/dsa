// A weak_ptr is created as a copy of shared_ptr.
// It provides access to an object that is owned by
// one or more shared_ptr instances but does not
// participate in reference counting. The existence or destruction of weak_ptr has
// no effect on the shared_ptr or its other copies. It
// is required in some cases to break circular references between shared_ptr instances.

// Problem with shared ptr
// Problems with shared_ptr):
// Let’s consider a scenario where we have two classes A and B, both have pointers to other classes.
// So, it’s always like A is pointing to B and B is pointing to A.
// Hence, use_count will never reach zero and they never get deleted.

// weak pointers(weak_ptr) as they are not reference counted.
// So, the class in which weak_ptr is declared
// doesn’t have a stronghold of it i.e. the ownership
// isn’t shared, but they can have access to these objects.

#include <bits/stdc++.h>
using namespace std;

weak_ptr<int> wptr;

void observe()
{
    cout << "Use count = " << wptr.use_count() << endl;
    if (auto spt = wptr.lock()) // Has to be copied into a shared_ptr before usage
    { 
        std::cout << *spt << "\n";
    }
    else
    {
        std::cout << "gw is expired \n";
    }
}

int main(int argc, char const *argv[])
{
    auto sp = make_shared<int>(42);
    wptr = sp;

    observe();

    return 0;
}
