
// Given weights and values of n items, put these items in a
// knapsack of capacity W to get the maximum total value in the knapsack. 
// In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights 
// associated with n items respectively. Also given an integer W which represents knapsack capacity, 
// find out the maximum value subset of val[]
// such that sum of the weights of this subset is smaller than or equal to W.
// You cannot break an item, You can pick same item multiple times

#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack_rec(int val[], int wt[], int w, int n)
{
    if(n == 0 || w == 0)
    {
        return 0;
    }
    else
    {
        if(wt[n - 1] > w)
        {
            return (unboundedKnapsack_rec(val, wt, w, n-1));
        }
        else
        {
            return(max(val[n-1] + unboundedKnapsack_rec(val, wt, w-wt[n-1], n), unboundedKnapsack_rec(val, wt, w, n-1)));
        }
    }
}

int dp[200][200];

int unboundedKnapsack_mem(int val[], int wt[], int w, int n)
{
    if(n == 0 || w == 0)
    {
        return 0;
    }
    if(dp[w][n] != -1)
    {
        return dp[w][n];
    }
    else
    {
        if(wt[n-1] > w)
        {
            dp[w][n] = unboundedKnapsack_mem(val, wt, w, n-1);
            return dp[w][n];
        }
        else
        {
            dp[w][n] = max(val[n-1] + unboundedKnapsack_mem(val, wt, w-wt[n-1], n) , unboundedKnapsack_mem(val, wt, w, n-1));
            return dp[w][n];
        }
    }
}

int unboundedKnapsack_bu(int val[], int wt[], int w, int n)
{
    int dp[n+1][w+1];
    // Init
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<w+1; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<w+1; j++)
        {
            if(wt[i-1] <= j)
            {
                dp[i][j] = max(val[i-1] + dp[i][j - wt[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    return dp[n][w];
}


int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);
    
    for(int i=0; i<200; i++)
    {
        for(int j=0; j<200;j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << unboundedKnapsack_rec(val, wt, W, n)<<endl;
    cout << unboundedKnapsack_mem(val, wt, W, n)<<endl;
    cout << unboundedKnapsack_bu(val, wt, W, n)<<endl;


    return 0;
}

