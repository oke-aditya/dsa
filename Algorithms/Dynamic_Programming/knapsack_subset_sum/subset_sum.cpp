// Given a set of non-negative integers, and a value sum,
// determine if there is a subset of the given set with sum equal to given sum.

// Input: N = 4
// arr = {1, 5, 11, 5}
// Output: YES
// Explaination: 
// The two parts are {1, 5, 5} and {11}.


#include<bits/stdc++.h>
using namespace std;


bool subset_sum_rec(vector<int> arr, int n, int sum)
{
    if(n == 0 && sum != 0)
    {
        return false;
    }

    if(sum == 0)
    {
        return true;
    }

    if(arr[n-1] > sum)
    {
        return subset_sum_rec(arr, n-1, sum);
    }

    else
    {
        return subset_sum_rec(arr, n-1, sum-arr[n-1]) || subset_sum_rec(arr, n-1, sum);
    }
}


bool subset_sum_mem(vector<int> arr, int n, int sum, vector<vector<int>> dp)
{
    if(dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if(n == 0 && sum != 0)
    {
        return false;
    }

    if(sum == 0)
    {
        return true;
    }

    if(arr[n-1] > sum)
    {
        dp[n][sum] = subset_sum_mem(arr, n-1, sum, dp);
        return dp[n][sum];
    }

    else
    {
        dp[n][sum] = subset_sum_mem(arr, n-1, sum-arr[n-1], dp) || subset_sum_mem(arr, n-1, sum, dp);
        return dp[n][sum];
    }
}

bool subset_sum_bu(vector<int> arr, int n, int sum, vector<vector<int>> dp)
{
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
            if(arr[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }

            else
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
        }
    }

    return dp[n][sum];

}



int main(int argc, char const *argv[])
{
    vector<int> v = {5, 2,  5, 1, 3};
    int n = v.size();
    int sum = 15;

    vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));

    if(subset_sum_rec(v, n, sum))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    if(subset_sum_mem(v, n, sum, dp))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    if(subset_sum_bu(v, n, sum, dp))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    
    return 0;
}





