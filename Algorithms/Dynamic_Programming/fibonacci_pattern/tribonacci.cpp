// Tribonacci Number
// The Tribonacci sequence Tn is defined as follows: 

// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

// Given n, return the value of Tn.

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4

// Input: n = 25
// Output: 1389537

#include<bits/stdc++.h>
using namespace std;

int tribonacci(int n) {
    
    if(n == 0)
    {
        return 0;
    }
    
    vector <int> res(n+2, 0);
    res[0] = 0;
    res[1] = 1;
    res[2] = 1;
    
    for(int i=3; i<=n; i++)
    {
        res[i] = res[i-1] + res[i-2] + res[i-3];
    }
    
    return res[n];
        
    
}

