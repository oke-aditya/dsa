// Pure virtual functions.
// 
// Sometimes implementation of all
// function cannot be provided in a base class
// because we don’t know the implementation. Such a class is called abstract class.
// For example, let Shape be a base class. We cannot provide implementation of
// function draw() in Shape, but we know every derived class must have implementation of draw(). 

// A pure virtual function is declared by assigning 0 in declaration.

// Virtual functions allow us to create a list of base class pointers and call
// methods of any of the derived classes without even knowing kind of derived class object. 
// A class is abstract if it has at least one pure virtual function. 
// A pure virtual function is implemented by classes which are derived from a Abstract class
// We can have pointers and references of abstract class type. 
// If we do not override the pure virtual function in derived class,
// then derived class also becomes abstract class.
// An abstract class can have constructors. 

#include<bits/stdc++.h>
using namespace std;

class Shape
{
    // Data members of the class
    public:
        virtual int area() = 0;
        virtual void print_area() = 0;

};

class Square : public Shape
{
    public:
        int length;

        Square(int length)
        {
            this->length = length;
        }

        int area()
        {
            return (this->length * this->length);
        }

        void print_area()
        {
            cout<<"Area of square = " <<this->area();
        }

};

class Rectange : public Shape
{
    public:
        int length, breadth;
    
        Rectange(int length, int breadth)
        {
            this->length = length;
            this->breadth = breadth;
        }

        int area()
        {
            return(this->length * this->breadth);
        }

        void print_area()
        {
            cout<<"Area of rectangle = "<<this->area();
        }
};


int main(int argc, char const *argv[])
{
    Square sq(10);
    cout<<sq.area()<<endl;
    sq.print_area();
    cout<<endl;

    Rectange rt(30, 10);
    cout<<rt.area()<<endl;
    rt.print_area();
    cout<<endl;

    // Or we cam use pointers too

    Shape *ptr;
    Square sq2(13);
    Rectange rt2(2, 4);

    ptr = &sq2;

    cout<<ptr->area()<<endl;
    ptr->print_area();

    ptr = &rt2;

    cout<<ptr->area()<<endl;
    ptr->print_area();

    cout<<endl;

    return 0;
}

