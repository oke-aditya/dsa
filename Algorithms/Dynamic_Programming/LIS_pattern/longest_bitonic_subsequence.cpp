// Longest Bitonic Subsequence 

// Given an array arr[0 … n-1] containing n positive integers, 
// a subsequence of arr[] is called Bitonic if it is first increasing, 
// then decreasing. 
// Write a function that takes an array as argument 
// and returns the length of the longest bitonic subsequence. 


// Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
// Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

// Input arr[] = {12, 11, 40, 5, 3, 1}
// Output: 5 (A Longest Bitonic Subsequence of length 5 is 12, 11, 5, 3, 1)

// Input arr[] = {80, 60, 30, 40, 20, 10}
// Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)


#include<bits/stdc++.h>

using namespace std;


int LongestBitonicSequence(vector<int>nums)
{
        
    int n = nums.size();
    vector<int> dp(n + 1, 1);
    vector<int> dp2(n + 1, 1);

    int res = -1;

    for(int i=0; i<n; i++)
    {
        for(int prev=0; prev<i; prev++)
        {
            if(nums[i] > nums[prev])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
    }
    // print_v(dp);
    // cout<<endl;
    
    // reverse LIS    
    for(int i=n-1; i>=0; i--)
    {
        for(int prev=n-1; prev>i; prev--)
        {
            if(nums[i] > nums[prev])
            {
                dp2[i] = max(dp2[i], 1 + dp2[prev]);
            }
        }
    }
    
    
    // print_v(dp2);
    // cout<<endl;

    for(int i=0; i<=n; i++)
    {
        res = max(res, dp[i] + dp2[i] - 1);
    }
    
    return res;
}