// Constructor has same name as the class itself
// Constructors don’t have return type
// A constructor is automatically called when an object is created.
// If we do not specify a constructor,
// C++ compiler generates a default constructor for us (expects no parameters and has an empty body).

// Types of constructors
// 1. Default Constructor.
// 2. Parameterized Constructor.
// 3. Copy Constructor.


#include<bits/stdc++.h>
using namespace std;

// 1. Default Constructor

class cons1
{
    public:
        int a, b;

        // Constructor
        cons1()
        {
            a = 10;
            b = 20;
        }
};


// 2. Parameterized Constructor

class cons2
{
    public:
        int x, y;

    cons2()
    {
        this->x = x;
        this->y = y;
    }
};


// 3. Copy constructor.
// A copy constructor is a member function which initializes an object using another object of the same class. 
// In C++, a Copy Constructor may be called in the following cases: 
// 1. When an object of the class is returned by value. 
// 2. When an object of the class is passed (to a function) by value as an argument. 
// 3. When an object is constructed based on another object of the same class. 
// 4. When the compiler generates a temporary object.

// Deep copy is possible only with user defined copy constructor
// In user defined copy constructor, we make
// sure that pointers (or references) of copied object point to new memory locations.  
// Assigning objects using = will lead to shallow copy, changes would be reflect in each other.

// Why argument to a copy constructor must be passed as a reference? 
// A copy constructor is called when an object is passed by value.
// Copy constructor itself is a function. So if we pass an argument
// by value in a copy constructor, a call to copy constructor would
// be made to call copy constructor which becomes a non-terminating
// chain of calls. Therefore compiler doesn’t allow parameters to be passed by value.

class Point
{
    private:
        int x, y;
    
    public:

        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
    
        // Copy Constructor
        Point(const Point &p1)
        {
            x = p1.x;
            y = p1.y;
        }

        int get_x()
        {
            return (this->x);
        }

        int get_y()
        {
            return (this->y);
        }

};


int main(int argc, char const *argv[])
{
    // Normal constructor is called here.
    Point p1(12, 10);

    // Copy constructor is called here
    Point p2 = p1;

    cout<<p1.get_x()<<" "<<p1.get_y()<<endl;
    cout<<p2.get_x()<<" "<<p2.get_y()<<endl;

    return 0;
}


