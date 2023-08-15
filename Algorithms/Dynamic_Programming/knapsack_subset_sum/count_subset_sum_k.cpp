// Number of subsets with sum equal to k.

// Given an array arr[] of length N and an integer X, 
// the task is to find the number of subsets with sum equal to X.

// Input: arr[] = {1, 2, 3, 3}, X = 6
// Output: 3

// Input: arr[] = {1, 1, 1, 1}, X = 1
// Output: 4 

#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int count_subset_sum(int arr[], int sum, int n)
{

    if(dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    // // base conditions
    if(n == 0) 
    {
        if(sum == 0) 
        {
            return 1;
        }
        return 0;
    }


    else
    {
        if(arr[n-1] > sum)
        {
            dp[n][sum] = (count_subset_sum(arr, sum, n-1));
        }
        else
        {
            dp[n][sum] = (count_subset_sum(arr, sum, n-1) + count_subset_sum(arr, sum-arr[n-1], n-1));
        }
        return dp[n][sum];
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 3, 5, 8, 10}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<n;
    for(int i=0; i<100; i++)
    {
        for(int j=0;j<100; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    int target = 10;
    cout<<count_subset_sum(arr, target, n);

    return 0;
}
