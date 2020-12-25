// https://www.geeksforgeeks.org/recursive-program-to-generate-power-set/
// Power Set Power set P(S) of a set S is the set of all subsets of S.
// For example S = {a, b, c} then P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.
// If S has n elements in it then P(s) will have 2^n elements

#include <bits/stdc++.h>
using namespace std;

// For unsorted cases use unordered set
unordered_set<string> s1;

// For lexicographically sorted case use normal set.
// set <string> s2;

// If question asks to print powerset, all subsets, or subsequences.
// Remove duplicates using set or unordered set.
// Also works for array of integers instead of strings.

void print_set(unordered_set <string> s)
{
    for(auto itr = s.begin(); itr != s.end(); itr++)
    {
        cout<<*itr<<" ";
    }

}

void solve(string inp, string op)
{

    if(inp.length() == 0)
    {
        // Add here to a result vector / set to print unique
        s1.insert(op);
        cout<<op<<" ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op2 += inp[0];
    inp.erase(inp.begin() + 0);
    solve(inp, op1);
    solve(inp, op2);
}

void powerSet(string str)
{

    string inp = str;
    string op = "";
    solve(inp, op);
    cout<<endl;
    print_set(s1);
}

int main(int argc, char const *argv[])
{
    string str = "aabc";
    powerSet(str);
    cout<<endl;
    return 0;
}
