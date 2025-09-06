// https://cses.fi/problemset/task/1094

// You are given an array of n integers. You want to modify the array so that it is increasing, 
// i.e., every element is at least as large as the previous element.
// On each move, you may increase the value of any element by one. 
// What is the minimum number of moves required?

// Input

// The first input line contains an integer n: the size of the array.
// Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.

// Output
// Print the minimum number of moves.

// Example
// Input:
// 5
// 3 2 5 1 7

// Output:
// 5

// Solution
// We can do a greedy O(n) Solution
// increase from left to right, after increasing mark the array as previous one

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    
    vector<int> arr(n);
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    long long count = 0;

    for(int i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) {
            count += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }

    cout<<count;

    return 0;

}
