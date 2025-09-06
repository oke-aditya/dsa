// A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
// Given n, construct a beautiful permutation if such a permutation exists.

// Input
// The only input line contains an integer n.

// Output
// Print a beautiful permutation of integers 1,2,\ldots,n. 
// If there are several solutions, you may print any of them.
// If there are no solutions, print "NO SOLUTION".

// Constraints

// 1 \le n \le 10^6

// Example 1
// Input:
// 5

// Output:
// 4 2 5 3 1
// Example 2
// Input:
// 3

// Output:
// NO SOLUTION

// Solution

// This is a constructive problem
// We can have multiple solution
// one way is to accumulate all even number, then the odd number

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin>>n;

    vector<int> res;

    // even numbers
    for(int i=2; i<=n; i=i+2) {
        res.push_back(i);
    }

    // odd numbers
    for(int i=1; i<=n; i=i+2) {
        res.push_back(i);
    }

    int n2 = res.size();

    for(int i=1; i<n2; i++) {
        if((res[i-1] - res[i]) == 1) {
            cout<<"NO SOLUTION";
            return 0;
        }
    }


    for(int i=0; i<n2; i++) {
        cout<<res[i]<<" ";
    }

}


