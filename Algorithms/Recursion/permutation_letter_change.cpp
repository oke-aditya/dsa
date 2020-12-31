// Print all possible strings that can be made by placing spaces

// Given a string you need to print all possible strings
// that can be made by placing spaces (zero or one) in
// between them. Output should be printed in sorted increasing order of strings.

// Input:  str[] = "ABC"
// Output: (A B C)(A BC)(AB C)(ABC)

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

    op1 += "_";
    op1 += inp[0];
    op2 += inp[0];
    inp.erase(inp.begin() + 0);

    solve(inp, op1);
    solve(inp, op2);
    return;
}

void perm_letter(string str)
{
    string inp = str;
    string op = "";

    op += inp[0];
    inp.erase(inp.begin() + 0);

    // cout<<inp<<endl;
    // cout<<op<<endl;

    solve(inp, op);
}

int main(int argc, char const *argv[])
{
    string str = "ABC";

    perm_letter(str);
    cout << endl;
    return 0;
}
