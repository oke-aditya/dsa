// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
// Below is one possible representation of A = “great”:

//  great
//    /    '\'
//   gr    eat
//  / '\'    /  '\'
// g   r  e   at
//            / '\'
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two children.

// For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

//     rgeat
//    /    '\'
//   rg    eat
//  / '\'    /  '\'
// r   g  e   at
//            / '\'
//           a   t
// We say that “rgeat” is a scrambled string of “great”.

// Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

//     rgtae
//    /    '\'
//   rg    tae
//  / '\'    /  '\'
// r   g  ta  e
//        / '\'
//       t   a
// We say that “rgtae” is a scrambled string of “great”.

// Input 1:
//     A = "we"
//     B = "we"

// Output 1:
//     1

// Input 2:
//     A = "phqtrnilf"
//     B = "ilthnqrpf"

// Output 2:
//     0

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

bool scrmbld_str_mem(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    if (s1.length() <= 1 || s2.length() <= 1)
    {
        return false;
    }

    if (s1 == s2)
    {
        return true;
    }

    string key = s1 + "_" + s2;

    if (mp.find(key) != mp.end())
    {
        return mp[key];
    }

    int n = s1.length();
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        if (
            scrmbld_str_mem(s1.substr(0, i), s2.substr(n - i, i)) && scrmbld_str_mem(s1.substr(i, n - i), s2.substr(0, n - i)) ||
            scrmbld_str_mem(s1.substr(0, i), s2.substr(0, i)) && scrmbld_str_mem(s1.substr(i, n - i), s2.substr(i, n - i)))
        {
            flag = true;
            mp[key] = flag;
            break;
        }
    }
    return flag;
}

bool scrmbld_str_rec(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    if (s1.length() <= 1 || s2.length() <= 1)
    {
        return false;
    }

    if (s1 == s2)
    {
        return true;
    }

    int n = s1.length();
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        if (
            scrmbld_str_rec(s1.substr(0, i), s2.substr(n - i, i)) && scrmbld_str_rec(s1.substr(i, n - i), s2.substr(0, n - i)) ||
            scrmbld_str_rec(s1.substr(0, i), s2.substr(0, i)) && scrmbld_str_rec(s1.substr(i, n - i), s2.substr(i, n - i)))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int main(int argc, char const *argv[])
{
    string s1 = "we";
    string s2 = "we";

    string s3 = "phqtrnilf";
    string s4 = "ilthnqrpf";

    cout << scrmbld_str_rec(s1, s2) << endl;
    cout << scrmbld_str_mem(s1, s2) << endl;

    cout << scrmbld_str_rec(s3, s4) << endl;
    cout << scrmbld_str_mem(s3, s4) << endl;

    return 0;
}
