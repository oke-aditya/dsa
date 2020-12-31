#include<iostream>
#include<stack>
using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) 
{
    stack<char> s1;
    s1.push(s[0]);
    for(int i=1; i<s.length(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            s1.push(s[i]);
        }
        else if(s[i] == '}')
        {
            if(s1.empty())
            {
                return "NO";
            }
            else if(s1.top() != '{')
            {
                return "NO";
            }
            else
            {
                s1.pop();
            }
        }
        else if(s[i] == ')')
        {
            if(s1.empty())
            {
                return "NO";
            }
            else if(s1.top() != '(')
            {
                return "NO";
            }
            else
            {
                s1.pop();
            }
        }
        else if(s[i] == ']')
        {
            if(s1.empty())
            {
                return "NO";
            }
            else if(s1.top() != '[')
            {
                return "NO";
            }
            else
            {
                s1.pop();
            }
        }
    }
    if(!s1.empty())
    {
        return "NO";
    }
    else
    {
        return "YES";
    }
}

int main(int argc, char const *argv[])
{
    string s = "{{[[(())]]}}";
    auto res = isBalanced(s);
    cout<<res;
    return 0;
}

