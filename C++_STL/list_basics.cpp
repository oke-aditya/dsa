#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std; 

void print_list(list <int> l1)
{
    for(auto x : l1)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    list <int> l1;
    list <int> l2;

    for(int i=1; i<10; i++)
    {
        l1.push_back(i);
        l2.push_front(i*2);
    }

    print_list(l1);
    print_list(l2);

    cout<<endl<<"Front element is : "<<l1.front();
    l1.pop_front();
    
    cout<<endl<<"Back element is : "<<l2.back();
    l2.pop_back();

    cout<<endl;

    print_list(l1);
    print_list(l2);

    return 0;
}

