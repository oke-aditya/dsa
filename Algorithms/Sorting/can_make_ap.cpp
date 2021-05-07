// A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

// Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

// Example 1:

// Input: arr = [3,5,1]
// Output: true
// Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with
// differences 2 and -2 respectively, between each consecutive elements.

// Example 2:

// Input: arr = [1,2,4]
// Output: false
// Explanation: There is no way to reorder the elements to obtain an arithmetic progression.

#include<bits/stdc++.h>
using namespace std;

bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    
    int exp_diff = arr[1] - arr[0];        
    
    for(int i=0; i<n-1; i++)
    {
        int j = i + 1;
        int calc_diff = arr[j] - arr[i];
        
        if(calc_diff != exp_diff)
        {
            return false;
        }
    }
    return true;
    }
