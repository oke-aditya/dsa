// https://leetcode.com/problems/target-sum/
// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+'
// and '-' before each integer in nums and then concatenate all the integers.

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be
// target 3. -1 + 1 + 1 + 1 + 1 = 3 +1 - 1 + 1 + 1 + 1 = 3 +1 + 1 - 1 + 1 + 1 =
// 3 +1 + 1 + 1 - 1 + 1 = 3 +1 + 1 + 1 + 1 - 1 = 3

// Here is the trick. Since we want number of ways to achieve target
// If we do subtract target from sum of array and it's -ve there is no way we can achieve that, insufficient numbers
// If it is odd, we still cannot achieve that.
// otherwise, we can check if we can achieve half of it via subset sum.
// we need print number of ways of subset sum

#include <bits/stdc++.h>

using namespace std;
class Solution {

  public:
      int is_subset_sum(int sum, vector<int> nums, int n) {
          
              vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
          
              // if n is 0
              for(int i=0; i<=n; i++) {
                  dp[i][0] = 1;
              }
          
              // if sum is 0;
              for(int i=0; i<=sum; i++) {
                  dp[0][i] = 0;
              }
          
              dp[0][0] = 1;
              for(int i=1; i<=n; i++) {
  
                  // j iterates from 0, note that sum can be equal to 0
                  for(int j=0; j<=sum; j++) {
                      
                      if(nums[i-1] > j) {
                          dp[i][j] = dp[i-1][j];
                      }
          
                      else {
                          dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                      }
                  }
              }
              return dp[n][sum];
          }
  
      int findTargetSumWays(vector<int>& nums, int target) 
      {
          int n = nums.size();
          int sum = accumulate(begin(nums), end(nums), 0);
  
          if((sum - target) % 2 != 0 || (sum - target) < 0)
          {
              return 0;
          }
  
          int new_sum = (sum - target) / 2;
          
          return is_subset_sum(new_sum, nums, n);
  
      }
  
  };