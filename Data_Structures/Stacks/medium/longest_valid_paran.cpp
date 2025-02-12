// Given a string containing parenthesis,
// find the length of the longest matching parenthesis

// See this example for better understanding.

// Input: (())()((()
// Output: 6 (from index 0 to 6)

// Solution: -

// Use a stack to keep track of indices of left paren

// For every ‘(’\text{‘(’}‘(’ encountered, we push its index onto the stack.

// For every ‘)’\text{‘)’}‘)’ encountered, we pop
// the topmost element and subtract the current element's index
// from the top element of the stack, which gives the length of
// the currently encountered valid string of parentheses.
// If while popping the element, the stack becomes empty,
// we push the current element's index onto the stack.
// In this way, we keep on calculating the lengths of the valid substrings,
// and return the length of the longest valid string at the end.


#include <bits/stdc++.h>

using namespace std;

int longest_valid_paran(string s1)
{
    if (s1.length() == 0)
    {
        return 0;
    }

    int i = 0, length, max_length = 0;
    
    // Stack stores indices.
    stack<int> stk;

    // Dummy.
    stk.push(-1);

    for (i = 0; i < s1.length(); i++)
    {
        // If brace is open, we accept it.

        if (s1[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            stk.pop();
            // If stack is empty, length = 0;
            if(stk.empty())
            {
                stk.push(i);
            }
            else
            {
                max_length = max(max_length, i - stk.top());
            }
        }
    }
    return max_length;
}

int main(int argc, char const *argv[])
{
    string s1 = "(())()((()";
    auto res = longest_valid_paran(s1);

    cout << res << endl;

    return 0;
}
