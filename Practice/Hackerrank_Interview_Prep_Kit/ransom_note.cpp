#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

void checkMagazine(vector<string> magazine, vector<string> note) 
{
    map <string, int> m1;

    for (auto x : magazine)
    {
        cout<<x<<" "<<endl;
    }
    
    for (auto x : note)
    {
        cout<<x<<" "<<endl;
    }

    for (auto x : magazine)
    {
        auto itrc = m1.find(x);
        if(itrc == m1.end())
        {
            m1[x] = 1;
        }
        else
        {
            m1[x] += 1;
        }
    }
    
    // for(auto itr1=m1.begin(); itr1 != m1.end(); itr1++)
    // {
    //     cout<<"Key: "<<itr1->first<<" "<<"Value: "<<itr1->second<<endl;
    // }

    for (auto x : note)
    {
        auto itrc = m1.find(x);
        if(itrc == m1.end() || itrc->second == 0)
        {
            cout<<"No";
            return;
        }
        else
        {
            m1[x] -= 1;
        }
    }
    cout<<"Yes";
    return;
}

int main(int argc, char const *argv[])
{
    // vector <string> s1 = {"give", "me", "one", "grand", "today", "night"};
    // vector <string> s2 = {"give", "one", "grand", "today"};
    
    vector <string> s1 = {"two", "times", "three", "is", "not", "four"};
    vector <string> s2 = {"two", "times", "two", "is", "four"};
    
    checkMagazine(s1, s2);

    return 0;
}


