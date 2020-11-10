// Given a set of non-negative integers, and a value sum,
// determine if there is a subset of the given set with sum equal to given sum.

#include<bits/stdc++.h>
using namespace std;

int dp[100][100];


bool is_subeset_sum_rec(int set[], int sum, int n)
{
    // Base Cases
    if(sum == 0)
    {
        return true;
    }
    if(n == 0)
    {
        return false;
    }

    // If the last element is greater, then we have to leave it
    if(set[n-1] > sum)
    {
        return (is_subeset_sum_rec(set, sum, n-1));
    }
    else
    {
        return (is_subeset_sum_rec(set, sum, n-1) || is_subeset_sum_rec(set, sum-set[n - 1], n-1));
    }
}

int is_subset_sum_mem(int set[], int sum, int n)
{
    if(dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if(sum == 0)
    {
        return 1;
    }
    if(n == 0)
    {
        return 0;
    }
    else
    {
        if(set[n-1] > sum)
        {
            dp[n][sum] = is_subset_sum_mem(set, sum, n-1);
            return dp[n][sum];
        }
        else
        {
            dp[n][sum] = is_subset_sum_mem(set, sum, n-1) || is_subset_sum_mem(set, sum-set[n-1], n-1);
            return dp[n][sum];
        }
    }
}

int is_subset_sum_bu(int set[], int sum, int n)
{
    bool dp[n+1][sum+1];

    // If sum is 0, then answer is true
    for(int i=0; i<n; i++)
    {
        dp[i][0] = true;
    }
    // If sum is not 0 and set is empty, 
    // then answer is false. It starts from 1.
    for (int i = 1; i <= sum; i++) 
    {
        dp[0][i] = false;
    }

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<sum+1; j++)
        {
            if(j < set[i - 1])
            {
                dp[i][j] = dp[i - 1][j]; 
            }
            else
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - set[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int main(int argc, char const *argv[])
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    int n = sizeof(set) / sizeof(set[0]);

    if(is_subeset_sum_rec(set, sum, n))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    for(int i=0; i<100; i++)
    {
        for(int j=0;j<100; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    if(is_subset_sum_mem(set, sum, n) == 1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    if(is_subset_sum_bu(set, sum, n) == 1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    
    return 0;
}





