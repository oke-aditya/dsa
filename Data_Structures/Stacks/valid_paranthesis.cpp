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
    stack <char> stk;
        
    for(char ch: s)
    {
        if(stk.empty() || ch == '(' || ch == '{' || ch == '[')
            stk.push(ch);
        
        else
        {
            char chk = stk.top();
            
            if(ch == ')' && chk != '(')
                return false;
            
            else if(ch == '}' && chk != '{')
                return false;
            
            else if(ch == ']' && chk != '[')
                return false;
            
            stk.pop();
        }
    }
    if(stk.empty())
        return true;
    else
        return false;
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


