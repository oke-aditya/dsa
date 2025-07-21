// https://cses.fi/problemset/task/1068

// Consider an algorithm that takes as input a positive integer n. 
// If n is even, the algorithm divides it by two, and if n is odd, 
// the algorithm multiplies it by three and adds one. 
// The algorithm repeats this, until n is one. 
// For example, the sequence for n=3 is as follows:

// Your task is to simulate the execution of the algorithm for a given value of n.
// Input
// The only input line contains an integer n.
// Output
// Print a line that contains all values of n during the algorithm.

// Example
// Input:
// 3

// Output:
// 3 10 5 16 8 4 2 1


#include <bits/stdc++.h>
using namespace std;

int main() {

    long long int n;
    cin>>n;

    while(n != 1) {
        cout<<n<<" ";
        if(n%2) {
            n = (n * 3) + 1;
        }
        else {
            n /= 2;
        }
    }

    cout<<n;


    return 0;
}


