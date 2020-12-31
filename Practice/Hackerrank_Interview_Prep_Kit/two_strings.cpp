#include<iostream>
#include<string>
#include<map>

using namespace std;

string twoStrings(string s1, string s2)
{
    string temp = "abcdefghijklmnopqrstuvwxyz";
    // cout<<temp.length();

    map <char, int> m1;
    map <char, int> m2;

    for(int i=0; i<temp.length(); i++)
    {
        m1[temp[i]] = 0;
        m2[temp[i]] = 0;
    }

    for(int i=0; i<s1.length(); i++)
    {
        m1[s1[i]] += 1;
    }

    for(int i=0; i<s2.length(); i++)
    {
        m2[s2[i]] += 1;
    }
    
    // for(auto itr=m1.begin(); itr != m1.end(); itr++)
    // {
    //     cout<<"Key = "<<itr->first<<" Value = "<<itr->second;
    // }

    // cout<<endl;
    // for(auto itr=m2.begin(); itr != m2.end(); itr++)
    // {
    //     cout<<"Key = "<<itr->first<<" Value = "<<itr->second;
    // }

    auto itr1 = m1.begin();
    auto itr2 = m2.begin();

    while (itr1 != m1.end() || itr2 != m2.end())
    {
        if(itr1->second >= 1 && itr2->second >= 1)
        {
            return "YES";
        }
        itr1++;
        itr2++;
    }

    return "NO";
}

int main(int argc, char const *argv[])
{
    // string s1 = "hello";
    string s1 = "abc";
    string s2 = "world";
    
    auto res = twoStrings(s1, s2);
    cout<<res;
    return 0;
}

