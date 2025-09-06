// std::future in C++

// std::future is a class template used to receive the result of an asynchronously executed task that 
// is not computed yet i.e. future value. 

// Asynchronous operations in C++ are managed using std::async, std::packaged_task, or std::promise, 
// which returns a std::future object. 

// We can use this std::future object to verify, await, or obtain the outcome of the operation.

#include <future>
#include <iostream>

using namespace std;

int return_two() {
    return 2;
}

int main() {
    future<int> f = async(launch::async, return_two);

    if(f.valid()) {
        cout<<"Value of future f:: "<<f.get()<<endl;
    }

    if(f.valid()) {
        cout<<"Value of future f:: "<<f.get()<<endl;
    }

    else {
        cout<<"Future value is invalid"<<endl;
    }

    return 0;

}

