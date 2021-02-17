#include<iostream>
#include<set>
#include<algorithm>
#include<iterator>

using namespace std;

int main(int argc, char const *argv[])
{
    set <int, greater <int>> s1;
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(20);
    s1.insert(10);
    s1.insert(10);
    
    set<int, int> :: iterator i1;
    cout<<"Set s1 is: ";
    for(i1=s1.begin(); i1 != s1.end(); i1++)
    {
        cout<<"\t "<<*i1;
    }
    cout<<endl;
    cout<<"Number of occurences of 10 = "<<s1.count(10)<<endl;
    cout<<"Number of occurences of 1 = "<<s1.count(1)<<endl;
    
    
    return 0;
}

