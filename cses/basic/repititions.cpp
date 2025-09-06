// https://cses.fi/problemset/task/1069

// You are given a DNA sequence: a string consisting of characters A, C, G, and T. 
// Your task is to find the longest repetition in the sequence. 
// This is a maximum-length substring containing only one type of character.

// Input
// The only input line contains a string of n characters.

// Output
// Print one integer: the length of the longest repetition.

// Constraints

// 1 \le n \le 10^6

// Example
// Input:
// ATTCGGGA

// Output:
// 3

// we can greedily optimize the max consecutive occurence. O(n)

#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin>>s;

    int count = 1, n = s.size(), max_count = 1;

    for(int i=1; i<n; i++) {
        if(s[i-1] == s[i]) {
            count += 1;
        }
        else {
            max_count = max(max_count, count);
            count = 1;
        }
    }

    max_count = max(max_count, count);
    cout<<max_count;
    
    return 0;

}
