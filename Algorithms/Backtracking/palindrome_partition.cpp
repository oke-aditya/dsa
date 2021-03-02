// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]

// Example 2:

// Input: s = "a"
// Output: [["a"]]

// Solution: -

#include<bits/stdc++.h>
using namespace std;

void print_vv(vector <vector<string>> vv)
{
    for(auto v : vv)
    {
        cout<<"[";
        for(auto ele: v)
        {
            cout<<ele<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
}


bool is_palindrome(string s, int low, int high)
{
    while(low < high)
    {
        if(s[low] != s[high])
        {
            return false;
        }
        low += 1;
        high -= 1;
    }
    return true;

}

void backtrack(vector<vector<string>> &res, vector<string> temp, string s, int start)
{
    if(start == s.length())
    {
        // We found the partition.
        res.push_back(temp);
    }

    else
    {
        for(int i=start; i<s.length(); i++)
        {
            if(is_palindrome(s, start, i))
            {
                temp.push_back(s.substr(start, i - start + 1));
                backtrack(res, temp, s, i + 1);
                temp.pop_back();
            }
        }        
    }
}

vector<vector<string>> pal_partitions(string s)
{
    vector <vector<string>> res;
    vector <string> temp;

    backtrack(res, temp, s, 0);
    return res;

}

int main(int argc, char const *argv[])
{
    string s1 = "aab";
    string s2 = "a";

    auto res1 = pal_partitions(s1);
    auto res2 = pal_partitions(s2);

    print_vv(res1);
    print_vv(res2);

    return 0;
}


