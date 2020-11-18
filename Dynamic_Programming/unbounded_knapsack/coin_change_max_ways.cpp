// Given a value N, if we want to make change for N cents,
// and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
// how many ways can we make the change? The order of coins doesn’t matter.
// Coins = {1, 2, 3};
// Change = 4

#include<bits/stdc++.h>
using namespace std;

int min_coin_rec(int coins[], int n, int change)
{
    // If we have no coin. There is no way to make any change
    if(n == 0)
    {
        return 0;
    }
    // If we don't have to make any change, we can do only with null set.
    if(change == 0)
    {
        return 1;
    }
    else
    {
        if(coins[n-1] > change)
        {
            // Coin is bigger, we ignore it.
            return (min_coin_rec(coins, n-1, change));
        }
        else
        {
            // Add all the possible coin choices. We take or we don't take.
            // If we take we can pick again, so just reduce the change.
            return (min_coin_rec(coins, n, change-coins[n-1]) + min_coin_rec(coins, n-1, change));
        }
    }
}

int dp[100][100];

int min_coin_mem(int coins[], int n, int change)
{
    // No coin we have
    if(n == 0)
    {
        return 0;
    }
    // No change to make, use empty set
    if(change == 0)
    {
        return 1;
    }
    if(dp[n][change] != -1)
    {
        return dp[n][change];
    }

    else
    {
        // A bigger coin
        if(coins[n-1] > change)
        {
            dp[n][change] = min_coin_mem(coins, n-1, change);
        }
        else
        {
            dp[n][change] = (min_coin_mem(coins, n, change-coins[n-1]) + min_coin_mem(coins, n-1, change));
        }
    }
    return dp[n][change];
}

int main(int argc, char const *argv[])
{
    int coins[] = {1, 2, 3};
    int n = sizeof(coins) / sizeof(coins[0]);
    int change = 4;
    cout<<min_coin_rec(coins, n, change)<<endl;

    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<min_coin_mem(coins, n, change)<<endl;

    return 0;
}

