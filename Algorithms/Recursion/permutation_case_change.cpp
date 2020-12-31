// Print all permutations of a string keeping the sequence but changing cases.

// Examples:

// Input : ab
// Output : AB Ab ab aB

#include <bits/stdc++.h>
using namespace std;

void solve(string inp, string op)
{
    if (inp.length() == 0)
    {
        cout << op << " ";
        return;
    }
    string op1 = op;
    string op2 = op;

    op1 += inp[0];
    op2 += toupper(inp[0]);
    inp.erase(inp.begin() + 0);

    solve(inp, op1);
    solve(inp, op2);
    return;
}

void perm_case_change(string str)
{
    string inp = str;
    string op = "";
    solve(inp, op);
}

int main(int argc, char const *argv[])
{
    string str = "ab";
    perm_case_change(str);
    cout<<endl;
    return 0;
}
