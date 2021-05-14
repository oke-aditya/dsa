// It is possible in C++ to get a special behavior for
// a particular data type. This is called template specialization. 

// An Example Program for function template specialization 
// For example, consider the following simple code where we have general template fun()
// for all data types except int. For int, there is a specialized version of fun(). 

#include<bits/stdc++.h>
using namespace std;

template <class T>
void fun(T a)
{
    cout<<"Template default function is called "<<endl;
}

template<>
void fun(int a)
{
    cout<<"Specialized template for int data type is called"<<endl;
}


int main(int argc, char const *argv[])
{
    fun <char>('a');
    fun <int>(10);
    
    return 0;
}



