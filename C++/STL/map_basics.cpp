#include<iostream>
#include<map>
#include<string>

using namespace std;
int main(int argc, char const *argv[])
{
    map<int, int> m1;
    m1[1] = 20;
    m1[2] = 40;

    for(auto itr=m1.begin(); itr != m1.end(); itr++)
    {
        cout<<itr->first<<"\t"<<itr->second<<endl;
    }

    map<char, int> m2;
    m2['a'] = 1;
    m2['b'] = 2;

    for(auto itr=m2.begin(); itr != m2.end(); itr++)
    {   
        cout<<itr->first<<"\t"<<itr->second<<endl;
    }

    auto it = m2.find('a');

    cout<<endl;
    cout<<it->first<<"\t"<<it->second<<endl;

    map<char, int> :: iterator it2;
    
    it2 = m2.find('c');

    if(it2 == m2.end())
    {
        cout<<"Key is not present in the map";
    }
    return 0;
}

