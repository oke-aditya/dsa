#include<bits/stdc++.h>

// Given weights and values of n items, put these items in a
// knapsack of capacity W to get the maximum total value in the knapsack. 
// In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights 
// associated with n items respectively. Also given an integer W which represents knapsack capacity, 
// find out the maximum value subset of val[]
// such that sum of the weights of this subset is smaller than or equal to W.
// You cannot break an item, either pick the complete item or don’t pick it (0-1 property).


using namespace std;

int dp[100][100];

int knapSackRec(int val[], int wt[], int w, int n)
{
    // Base Case
    if(n == 0 || w == 0)
    {
        return 0;
    }
    else
    {
        if(wt[n-1] > w)
        {
            return knapSackRec(val, wt, w, n-1);
        }
        // wt[n] < w
        else
        {
            return (
                max(val[n-1] + 
                knapSackRec(val, wt, w-wt[n-1], n - 1), 
                knapSackRec(val, wt, w, n-1)));
        } 
    }
    
}

int knapsack_mem(int val[], int wt[], int w, int n)
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
            dp[w][n] = knapsack_mem(val, wt, w, n-1);
            return dp[w][n];    
        }
        // wt[n] < w
        // else if(wt[n-1] <= w)
        else
        {
            dp[w][n] = max(val[n-1] + knapsack_mem(val, wt, w-wt[n-1], n - 1), knapsack_mem(val, wt, w, n-1));
            return dp[w][n];
        } 
    }
}

int knapsacl_bu(int val[], int wt[], int w, int n)
{
    // The recursive call has to be initialized
    int i;
    int dp[n+1][w+1];
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0 || j==0)
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
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][w];
}

int main(int argc, char const *argv[])
{
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int w = 50; 
    int n = sizeof(val) / sizeof(val[0]);

    for(int i=0; i<100; i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapSackRec(val, wt, w, n) <<endl; 
    cout << knapsack_mem(val, wt, w, n) <<endl;
    cout<< knapsacl_bu(val, wt, w, n) <<endl;
    return 0;
}

