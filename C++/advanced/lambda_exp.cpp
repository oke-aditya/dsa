// C++ 11 introduced lambda expression to allow
// us write an inline function which can be used for
// short snippets of code that are not going to
// be reuse and not worth naming.

// [ capture clause ] (parameters) -> return-type  
// {   
//    definition of method   
// } 

#include<bits/stdc++.h>

using namespace std;

void print_vector(vector <int> v)
{
    for_each(v.begin(), v.end(), [] (int i)
    {
        std::cout<<i<<" ";
    }
    );
}


int main(int argc, char const *argv[])
{
    vector<int> v {4, 1, 3, 5, 2, 3, 1, 7};
  
    print_vector(v);

    cout<<endl;

    vector<int>:: iterator p = find_if(v.begin(), v.end(), [](int i)
    {
        return i > 4;
    });

    cout<<"First number greater than 4 = "<<*p<<endl;
    
    // function to sort vector, lambda expression is for sorting in
    // non-decreasing order Compiler can make out return type as
    // bool, but shown here just for explanation
    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
    {
        return a > b;
    });
  
    print_vector(v);

    cout<<endl;

    return 0;
}

