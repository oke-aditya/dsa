#include<bits/stdc++.h>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(begin(nums), end(nums));

    int n = nums.size(), prev = -1, maxi =-1;
    vector<int> dp(n + 1);

    for(int i=0; i<n; i++)
    {
        for(int prev=0; prev<i; prev++)
        {
            if(nums[i] % nums[prev] == 0)
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    vector<int> res;
    prev = -1;

    for(int i=n-1; i>=0; i--)
    {
        if(dp[i] == maxi && (prev == -1 ||  prev % nums[i] == 0))
        {
            res.push_back(nums[i]);
            maxi -= 1;
            prev = nums[i];
        }
    }

    reverse(begin(res), end(res));
    return res;
}