// Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

// Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.

// The Fibonacci numbers are defined as:

//     F1 = 1
//     F2 = 1
//     Fn = Fn-1 + Fn-2 for n > 2.

// It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.

 

// Example 1:

// Input: k = 7
// Output: 2 
// Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
// For k = 7 we can use 2 + 5 = 7.

#include<bits/stdc++.h>
using namespace std;

int findMinFibonacciNumbers(int k) 
{
    int first = 1, second = 1;
    int sum = 2;

    vector<int> dp;
    dp.push_back(first);
    dp.push_back(second);

    // int count = 0;

    int i = 0;

    while(i <= 42)
    {
        int next = first + second;
        first = second;
        second = next;

        // sum += next;

        dp.push_back(next);
        i += 1;
        // count += 1;
        // cout<<next;
        // i++;
    }

    reverse(begin(dp), end(dp));

    int count = 0;

    for(auto x: dp)
    {
        if(k == 0)
        {
            break;
        }

        if(x <= k)
        {
            // cout<<x<<" "<<k<<endl;
            k -= x;
            count += 1;
        }
    }

    return count;


    // return count-1;
}

