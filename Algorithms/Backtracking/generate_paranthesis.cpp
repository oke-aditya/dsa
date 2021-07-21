// https://leetcode.com/problems/generate-parentheses

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Solution: -

// Backtracking

// The only 2 conditions are open < n and close < open.
// Also if no of brackets == 2 * n we get a result.

#include<bits/stdc++.h>
using namespace std;

void backtrack(vector <string> &res, string s, int open, int close, int n)
{
    if(s.length() == n * 2)
    {
        res.push_back(s);
        return;
    }
    
    if(open < n)
        backtrack(res, s + "(", open+1, close, n);
    
    if(close < open)
        backtrack(res, s + ")", open, close+1, n);
    
    
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string s = "";
    backtrack(res, s, 0, 0, n);
    
    return res;
    
}
