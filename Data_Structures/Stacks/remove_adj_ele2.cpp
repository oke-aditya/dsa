// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

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
    int i=0;
    int n = s.size();
    while(i<n)
    {
        if(stk.empty())
        {
            stk.push(make_pair(s[i], 1));
        }

        else if(stk.top().first != s[i])
        {
            stk.push(make_pair(s[i], 1));
        }

        else if(stk.top().first == s[i])
        {
            pair<char, int> top_pair = stk.top();
            top_pair.second += 1;
            stk.pop();
            stk.push(top_pair);
        }

        // check and pop the top
        pair<char, int> top_pair = stk.top();
        if(top_pair.second == k)
        {
            stk.pop();
        }
        i += 1;
    }

    string res = "";
    while(!stk.empty())
    {
        // Add number of times the char was present
        int count_pop = stk.top().second;
        for(int i=0; i<count_pop; i++)
        {
            res += stk.top().first;
        }
        // Pop the char
        stk.pop();
    }
    reverse(begin(res), end(res));
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


