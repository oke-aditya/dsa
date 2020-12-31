// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isvalid(string s)
{
    stack <char> s1;
    s1.push(s[0]);

    for(int i=1; i<s.length(); i++)
    {
        if(s[i] == '(')
        {
            s1.push(s[i]);
        }
        else if(s[i] == '[')
        {
            s1.push(s[i]);
        }
        else if(s[i] == '{')
        {
            s1.push(s[i]);
        }
        else if(s[i] == ')')
        {
            if(s1.empty())
            {
                return false;
            }

            char chk = s1.top();
            if(chk != '(')
            {
                return false;
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
                return false;
            }

            char chk = s1.top();
            if(chk != '[')
            {
                return false;
            }
            else
            {
                s1.pop();
            }
        }
        else if(s[i] == '}')
        {
            if(s1.empty())
            {
                return false;
            }
            char chk = s1.top();
            if(chk != '{')
            {
                return false;
            }
            else
            {
                s1.pop();
            }
        }
    }
    if(!s1.empty())
    {
        return false;
    }
    else
    {
        return true;
    } 
}

int main(int argc, char const *argv[])
{
    string s = "[";
    string s1 = "((([])))";
    string s2 = "(){}}{";
    if(isvalid(s2))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    
    return 0;
}


