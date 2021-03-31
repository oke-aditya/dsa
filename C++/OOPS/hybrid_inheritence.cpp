// Hybrid inheritence example

//              Class A
//   Class B                  Class C
//              Class D

#include<bits/stdc++.h>
using namespace std;

class A
{
    public:
        int a;
};

class B : public A
{
    public:
        int b;
};

class C : public A
{
    public:
        int c;
};

class D : public B, public C
{
    public:
        int d;
};


int main(int argc, char const *argv[])
{
    D obj;
    

    return 0;
}

