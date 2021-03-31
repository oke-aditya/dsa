#include<bits/stdc++.h>

// Shared_ptr
// A shared_ptr is a container for raw pointers.
// It is a reference counting ownership model i.e. it maintains
// the reference count of its contained pointer in
// cooperation with all copies of the shared_ptr.
// So, the counter is incremented each time a new pointer
// points to the resource and decremented when the destructor of the object is called.
// 
// Reference Counting: It is a technique
// of storing the number of references, pointers or handles
// to a resource such as an object, block of memory, disk space or other resources.

// Use shared_ptr if you want to share
// ownership of a resource. Many shared_ptr can point to a single resource.
// shared_ptr maintains reference count for
// this propose. when all shared_ptr’s pointing to resource goes out of scope the resource is destroyed.

using namespace std;

class Simple
{
    public:
        void show()
        {
            cout<<"Show method called"<<endl;
        }
};


int main(int argc, char const *argv[])
{
    shared_ptr <Simple> p1(new Simple);
    cout<<p1.get();

    shared_ptr <Simple> p2(p1);
    p2->show();

    cout<<p1.get()<<endl;
    cout<<p2.get()<<endl;


    // Return number of shared_ptr objects.
    // Referring to same managed object.
    cout<<p1.use_count()<<endl;
    cout<<p2.use_count()<<endl;

    // Remove ownership from objects
    p1.reset();
    
    cout<<p1.get()<<endl;
    cout<<p2.use_count()<<endl;
    cout<<p2.get()<<endl;

    return 0;
}

