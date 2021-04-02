#include<iostream>
#include<exception>

using namespace std;

class MyException : public std::exception
{
    public:
        const char *what () const throw()
        {
            return "C++ Custom exception";
        }

};

int main(int argc, char const *argv[])
{
    try
    {
        throw MyException();
    }
    catch(MyException & e)
    {
        cout << e.what() <<endl;
    }

    catch(exception &e)
    {
        cout<<"Any other errors"<<endl;
    }
    
    return 0;
}


