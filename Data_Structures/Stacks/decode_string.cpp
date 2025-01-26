// https://leetcode.com/problems/decode-string/

// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"

// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"

#include<bits/stdc++.h>

using namespace std;

string decodeString(string s) 
{
    stack<char> stk;

    int n = s.size();

    for(int i=0; i<n; i++)
    {
        if(s[i] != ']')
        {
            stk.push(s[i]);
        }

        else
        {
            string curr_str = "";
            while(stk.top() != '[')
            {
                curr_str = stk.top() + curr_str;
                stk.pop();
            }
            // for opening '['
            stk.pop();

            // Now number note that number can be2 digit number also don't forget.
            string number = "";
            while(!stk.empty() && isdigit(stk.top()))
            {
                number = stk.top() + number;
                stk.pop();
            }

            int k_times = stoi(number);
            while(k_times--)
            {
                // repeat the string these many times
                for(int i=0; i<curr_str.size(); i++)
                {
                    stk.push(curr_str[i]);
                }
            }
        }
    }
    string res = "";
    while(!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }

    reverse(begin(res), end(res));
    return res;
}


