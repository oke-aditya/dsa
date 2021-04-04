// Write code to reverse a string using stack

#include<bits/stdc++.h>
using namespace std;

string rev_string_stack(string s)
{
    stack <char> st;
    string res = "";

    for(int i=0; i<s.length(); i++)
    {
        st.push(s[i]);
    }

    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;

}

int main(int argc, char const *argv[])
{

    string s = "abc";
    cout<<s<<endl;

    auto res = rev_string_stack(s);

    cout<<res<<endl;


    return 0;
}

