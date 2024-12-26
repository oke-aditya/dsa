

#include<bits/stdc++.h>

using namespace std;



// check paldindrome between two indices of string.
bool is_palindrome(string s, int start, int end)
{
    while(start <= end)
    {
        if(s[start] != s[end])
        {
            return false;
        }
        start += 1;
        end -= 1;
    }
    return true;
}


// Trick here is to capture every palindrome as wel iterate.
// We can continously check if they are palindrome
// Note the substring size here would be between start and where 'i' pointer is.
// At the end we will have solutions

void backtrack(string s, int start, vector<string> &sol, vector<vector<string>> &res)
{
    // we will get solutions on leaf nodes
    if(start == s.size())
    {
        res.push_back(sol);
        return;
    }

    for(int i=start; i<s.size(); i++)
    {
        if(is_palindrome(s, start, i))
        {
            sol.push_back(s.substr(start, i - start + 1));
            backtrack(s, i+1, sol, res);
            sol.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> sol;
    int start = 0;
    backtrack(s, start, sol, res);
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "naman";

    auto res = partition(s);


    return 0;
}

