// https://cses.fi/problemset/task/1083

// You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.

// Input
// The first input line contains an integer n.
// The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).

// Output
// Print the missing number.

// Example

// Input:

// 5
// 2 3 1 5

// Output:

// 4


// solution:
// we can do this via expected sum - actual sum


#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main() {

    long long n;
    cin>>n;

    int new_n = n - 1;

    vector<long long> nums;

    while(new_n--) {
        long long i;
        cin>>i;
        nums.push_back(i);
    }

    long long sm = accumulate(begin(nums), end(nums), 0LL);
    long long calc2 = 1LL * n * (n + 1) / 2;
    cout<<(calc2 - sm);


}


