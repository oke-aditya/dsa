// Given a string s, a k duplicate
// removal consists of choosing k adjacent and equal letters from s
// and removing them causing the left and the
// right side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made.

// It is guaranteed that the answer is unique.

// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation: 
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"


#include<bits/stdc++.h>
using namespace std;

string remove_adj(string s, int k)
{

    // Stack of Pair to store character and count.
    stack<pair<char, int>> stk;
    string res = "";
    
    for(char ch: s)
    {
        // first occurence.
        if(stk.empty())
        {
            stk.push({ch, 1});
        }
        
        else
        {
            // If character matches.
            if(stk.top().first == ch)
            {
                // count is k - 1
                if(stk.top().second == (k - 1))
                {
                    stk.pop();
                }
                else
                {
                    stk.top().second += 1;
                }
            }
            // character did not match.
            else
            {
                stk.push({ch, 1});
            }
        }
    }
    
    // just pop the stack and add
    // character count number of times.
    while(!stk.empty())
    {
        int count = stk.top().second;
        while(count > 0)
        {
            res += stk.top().first;
            count -= 1;
        }
        stk.pop();
    }
    
    reverse(res.begin(), res.end());
    return res;
}



int main(int argc, char const *argv[])
{
    string s1 = "abcd";
    int k1 = 2;

    string s2 = "deeedbbcccbdaa";
    int k2 = 3;

    auto res1 = remove_adj(s1, k1);
    auto res2 = remove_adj(s1, k2);
    

    cout<<res1<<endl;
    cout<<res2<<endl;

    return 0;
}


