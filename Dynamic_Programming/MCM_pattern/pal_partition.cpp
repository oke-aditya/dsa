// Given a string, a partitioning of the string is a palindrome partitioning
// if every substring of the partition is a palindrome.

// Input : str = “geek”
// Output : 2
// We need to make minimum 2 cuts, i.e., “g ee k”

// Input : str = “aaaa”
// Output : 0
// The string is already a palindrome.

// Input : str = “abcde”
// Output : 4

#include<bits/stdc++.h>
using namespace std;

int pal_par_mem(string s, int n)
{

}


int main(int argc, char const *argv[])
{
    string s = "ababbbabbababa";
    int n = s.length();
    cout<<pal_par_mem(s, n)<<endl;

    return 0;
}
