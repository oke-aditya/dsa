// Static variables and methods in C++

#include<bits/stdc++.h>
using namespace std;

// Static members are shared among all objects.
// That is why they are also known as class members or class fields.
// Also, static members can be accessed without any object.

class st1
{
    public:
        static int count;
        int a, b;

        // Constructor
        st1(int a, int b)
        {
            this->a = a;
            this->b = b;
            count += 1;
        }
    
        // Note that we cannot use this-> with static member
        // This is wrong
        // this->count += 1;

        // We can even declare static methods

        static int show_count()
        {
            return count;
        }
};

// We also need to write a declaration outside.
int st1 :: count = 0;


int main(int argc, char const *argv[])
{
    st1 n1(10, 20), n2(30, 40), n3(50, 60);

    
    cout<<st1::show_count()<<endl;
    cout<<st1::count<<endl;


    return 0;
}

