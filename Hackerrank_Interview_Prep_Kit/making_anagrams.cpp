#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int makeAnagram(string a, string b)
{
    string az = "abcdefghijklmnopqrstuvwxyz";
    map <char, int> m1;
    map <char, int> m2;

    for(auto x : az)
    {
       m1[x] = 0;
    }

    for(auto x : az)
    {
        m2[x] = 0;
    }

    for(auto x: a)
    {
        m1[x] += 1;
    }

    for(auto x: b)
    {
        m2[x] += 1;
    }
    
    auto itr1 = m1.begin();
    auto itr2 = m2.begin();
    int anadiff = 0;

    while(itr1 != m1.end() || itr2 != m2.end())
    {
        anadiff += abs(itr1->second - itr2->second);
        itr1++;
        itr2++;
    }
    return anadiff;
}

int main(int argc, char const *argv[])
{
    string a = "cde";
    string b = "abc";
    int n = 3;
    int m = 4;
    // cout<<abs(n - m);
    cout<<makeAnagram(a, b);
    return 0;
}

