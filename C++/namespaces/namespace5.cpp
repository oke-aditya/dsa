// Using namespace in header files

// Use "" to include local header files
#include "simple_header.h"
#include<iostream>

int main(int argc, char const *argv[])
{
    std::cout<<foo::value()<<std::endl;
    return 0;
}

