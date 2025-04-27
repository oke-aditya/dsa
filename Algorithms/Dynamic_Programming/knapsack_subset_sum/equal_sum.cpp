// https://leetcode.com/problems/partition-equal-subset-sum/description/
// Partition problem is to determine whether a
// given set can be partitioned into two subsets such that the sum of elements
// in both subsets is the same.

// arr[] = {1, 5, 11, 5}
// Output: true
// The array can be partitioned as {1, 5, 5} and {11}

// arr[] = {1, 5, 3}
// Output: false
// The array cannot be partitioned into equal sum sets.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool is_subset_sum(int sum, vector<int> nums, int n) {
        
            vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
        
            // if n is 0
            for(int i=0; i<=n; i++) {
                dp[i][0] = true;
            }
        
            // if sum is 0;
            for(int i=0; i<=sum; i++) {
                dp[0][i] = false;
            }
        
            dp[0][0] = true;
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=sum; j++) {
                    
                    if(nums[i-1] > j) {
                        dp[i][j] = dp[i-1][j];
                    }
        
                    else {
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                    }
                }
            }
        
            return dp[n][sum];
        
        }
    
    
        bool canPartition(vector<int>& nums) {
        // find the sum of the element first
        int sum = accumulate(begin(nums), end(nums), 0);
    
        // now if the half sum is achievable as subset sum, we are good
        // we can't achieve odd sums of course
        if(sum % 2) {
            return false;
        }
    
        // guaranteed divisible
        int half_sum = sum / 2;
        int n = nums.size();
    
        
        return is_subset_sum(half_sum, nums, n);
    
        }
    };