// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

// You are given an integer array nums of 2 * n integers. 
// You need to partition nums into two arrays of length n to minimize the absolute difference 
// of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
// 
// Return the minimum possible absolute difference.

// Input: nums = [3,9,7,3]
// Output: 2
// Explanation: One optimal partition is: [3,9] and [7,3].
// The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.


#include<bits/stdc++.h>
using namespace std;

int minsubset_sum(int arr[], int n, int s1, int s2)
{
    // Base Case

    // IF list becomes empty return absolute difference
    if(n < 0)
    {
        return(abs(s1 - s2));
    }
    else
    {
        // Include in subset 1
        int inc = minsubset_sum(arr, n-1, s1 + arr[n], s2);
        int exc = minsubset_sum(arr, n-1, s1, s2 + arr[n]);
        return min(inc, exc);
    }
}

unordered_map<string, int> lookup;

int minsubset_sum_memo(int arr[], int n, int s1, int s2)
{
    // Base case
    if(n < 0)
    {
        return(abs(s1 - s2));
    }
    else
    {
        // Construct a dynamic key
        string key = to_string(n) + "|" + to_string(s1);
        
        // Try to find if key has solution. If not then solve it
        if(lookup.find(key) == lookup.end())
        {
            // Case 1 include in first subset
            int inc = minsubset_sum_memo(arr, n-1, s1 + arr[n], s2);

            // Case 2 include in second subset
            int exc = minsubset_sum_memo(arr, n-1, s1, s2 + arr[n]);

            // Assign it
            lookup[key] = min(inc, exc);
        }
        return lookup[key];
    }
}


int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 5, 15, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    auto minsum1 = minsubset_sum(arr, n-1, 0, 0);
    auto minsum2 = minsubset_sum_memo(arr, n-1, 0, 0);
        
    cout<<minsum1<<endl;
    cout<<minsum2<<endl;

    return 0;
}


