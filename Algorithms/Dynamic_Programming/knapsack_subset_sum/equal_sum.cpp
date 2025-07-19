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
    bool canPartition(vector<int>& nums) {
        // get half of the sum;

        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum % 2)
            return false;


        int half_sum = sum / 2;
        int n = nums.size();
        // subset sum dp;
        vector<vector<bool>> dp(n+1, vector<bool>(half_sum+1, false));

        for(int i=0; i<=n; i++) {
            for(int j=0; j<=half_sum; j++) {
                // if sum == 0, j == 0;
                if(j == 0) {
                    dp[i][j] = true;
                }
            }
        }

        // if n == 0 and sum == 0
        dp[0][0] = true;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=half_sum; j++) {
                
                if(nums[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[n][half_sum];
    }
};
