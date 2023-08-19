// Given an integer array nums, return the length of the longest strictly increasing
// subsequence.
// https://leetcode.com/problems/longest-increasing-subsequence/

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

#include<bits/stdc++.h>
using namespace std;

int helper(int idx, int prev_idx, vector<int> &nums, int n, vector<vector<int>> dp)
{

    if(idx == n)
    {
        return 0;
    }

    if(dp[idx][prev_idx+1] != -1)
    {
        return dp[idx][prev_idx+1];
    }

    // don't take
    // simply advance the index without updating the previous index.
    int res1 = 0, res2 = 0;
    
    res1 = helper(idx+1, prev_idx, nums, n, dp);
    if(prev_idx == -1 || nums[idx] > nums[prev_idx])
    {
        res2 = 1 + helper(idx+1, idx, nums, n, dp);
    }

    dp[idx][prev_idx+1] = max(res1, res2);
    return dp[idx][prev_idx+1];

}

int lengthOfLIS(vector<int>& nums) {
    int idx = 0, prev = -1, n = nums.size();
    
    // since we started the previous index from -1. We need 1 extra.
    vector<vector<int>> dp(n+1, vector<int>(n + 1, -1));

    int res = helper(idx, prev, nums, n, dp);
    return res;
}


int lengthOfLIS2(vector<int>& nums) {
    int idx = 0, prev = -1, n = nums.size();
    
    // since we started the previous index from -1. We need 1 extra.
    vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

    for(int i=n-1; i>=0; i--)
    {
        for(int j=i-1; j>=-1; j--)
        {
            int res1 = dp[i+1][j+1];
            int res2 = 0;
            if(j == -1 || nums[i] > nums[j])
            {
                res2 = 1 + dp[i+1][j+1];
            }
            dp[i][j+1] = max(res1, res2);
        }
    }
    return dp[0][0];
}

void print_v(vector<int> v)
{
    for(auto x: v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int lengthOfLIS3(vector<int>& nums) {
    int idx = 0, prev = -1, n = nums.size();
    vector<int> dp(n, 1);

    int res = 1;

    for(int i=0; i<n; i++)
    {
        for(int prev=0; prev<i; prev++)
        {
            if(nums[prev] < nums[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        res = max(dp[i], res);
    }

    print_v(dp);

    // to print LIS

    int mx = res;

    vector<int>lis;

    for(int i = n-1;i>=0;--i)
    {
        if(dp[i] == mx) 
        {
            lis.push_back(nums[i]);
            mx--;
        }
    }
    reverse(begin(lis),end(lis));
    
    return res;

}

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

int main(int argc, char const *argv[])
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    auto res = lengthOfLIS3(nums);
    cout<<res;
    return 0;

    int n = nums.size();

    vector<int> dp(n + 1);
    int prev = -1;
    int res = -1;
    for(int i=0; i<n; i++)
    {
        for(prev = 0; prev<i; prev++)
        {
            if(nums[i] > nums[prev])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
            res = max(res, dp[i]);
        }
    }

}

