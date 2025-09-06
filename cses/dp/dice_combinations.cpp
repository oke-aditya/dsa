// Your task is to count the number of ways to construct sum n by throwing a dice one or more times. 
// Each throw produces an outcome between 1 and  6.
// For example, if n=3, there are 4 ways:

// 1+1+1
// 1+2
// 2+1
// 3

// Input
// The only input line has an integer n.
// Output
// Print the number of ways modulo 10^9+7.

// Constraints

// Example
// Input:
// 3

// Output:
// 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    cout<<(1 << (n-1))<<endl;
    
    return 0;
}
