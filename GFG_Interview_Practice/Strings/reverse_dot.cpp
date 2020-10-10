// Given a String of length S, 
// reverse the whole string without reversing the individual words in it. 
// Words are separated by dots.

// Input
// 2
// i.like.this.program.very.much
// pqr.mno

// Output
// much.very.program.this.like.i
// mno.pqr

#include<bits/stdc++.h>
using namespace std;

void reverse_string(string &s)
{
    int start = 0;
    for(int i=0; i<s.length(); i++)
    {
        // If we see "." reverse the previous
        // word between start and end - 1
        if(s[i] == '.')
        {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    // Reverse the last word
    reverse(s.begin() + start, s.end());

    // Reverse the entire string
    reverse(s.begin(), s.end());

    cout<<s<<endl;
}

int main(int argc, char const *argv[])
{
    int n = 2;
    string s1 = "i.like.this.program.very.much";
    string s2 = "pqr.mno";

    reverse_string(s1);
    reverse_string(s2);

    return 0;
}


