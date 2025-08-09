// Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
// Input
// The only input line contains an integer n.
// Output
// Print "YES", if the division is possible, and "NO" otherwise.
// After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.

// Constraints

// 1 \le n \le 10^6

// Example 1
// Input:
// 7

// Output:
// YES
// 4
// 1 2 4 7
// 3
// 3 5 6
// Example 2
// Input:
// 6

// Output:
// NO

// Solution
// Do a Greedy approach
// Divide into two sets, maintaining running sum
// wherever sum is shorter, allocate next number


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    cin>> n;

    long long sum1 = 0, sum2 = 0;
    vector<int> v1, v2;

    for(int i=n; i>=1; i--) {

        if(sum1 < sum2) {
            sum1 += i;
            v1.push_back(i);
        }

        else {
            sum2 += i;
            v2.push_back(i);
        }
    }

    if(sum1 == sum2) {
        cout<<"YES"<<endl;
        cout<<v1.size()<<endl;

        for(auto x: v1) {
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<v2.size()<<endl;
        for(auto x: v2) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    else {
        cout<<"NO"<<endl;
    }
}

