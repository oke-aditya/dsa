// https://cses.fi/problemset/task/1618

// Your task is to calculate the number of trailing zeros in the factorial n!.
// For example, 20!=2432902008176640000 and it has 4 trailing zeros.
// Input
// The only input line has an integer n.
// Output
// Print the number of trailing zeros in n!.

// Constraints

// Example
// Input:
// 20

// Output:
// 4

// Solution:
// Every 5 provides 1 trailing 0
// Every 25 provides 2 trailing zeros
// Every 125 provides 3 trailing zeros

// Trailing zeros =
// sum(n / 5 + n / 25 + n / (multiple of 5 less than n))

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    int count = 0;

    for(int i=5; i<=n; i*=5) {
        count += (n / i);
    }

    cout<<count<<endl;
    return 0;

}



