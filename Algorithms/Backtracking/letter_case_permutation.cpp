// https://leetcode.com/problems/letter-case-permutation/description/

// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]

// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]


#include<bits/stdc++.h>
using namespace std;

void print_vs(vector<string> vv)
{
    for(auto s: vv)
    {
        cout<<s<<", ";
    }
}

void backtrack(string &s, int start, string &sol, vector<string> &res)
{
    // string size gives 4.
    if(start == s.size())
    {
        res.push_back(sol);
        return;
    }

    // notice we don't need for loop here, we are trying to use all combinations.
    // We are not trying to combine 2 elements / together in array.
    if(isalpha(s[start]))
    {
        // it's not OR case, we need both the combinations.
        // In case interviewer twists the question asking to ToGGLe we can add if here.

        sol += tolower(s[start]);
        backtrack(s, start+1, sol, res);
        sol.pop_back();

        sol += toupper(s[start]);
        backtrack(s, start+1, sol, res);
        sol.pop_back();
    }
    else
    {
        sol += s[start];
        backtrack(s, start+1, sol, res);
        sol.pop_back();
    }
    
}


vector<string> letterCasePermutation(string s) {
    vector<string> res;
    int start = 0;
    string sol = "";

    backtrack(s, start, sol, res);

    return res;
}

int main(int argc, char const *argv[])
{
    string s = "a1b2";
    // cout<<s.size()<<endl;
    auto res = letterCasePermutation(s);
    print_vs(res);

    return 0;
}
