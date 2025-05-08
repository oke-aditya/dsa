// https://leetcode.com/problems/jump-game-ii/description/

// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. 
// In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n

// Return the minimum number of jumps to reach nums[n - 1]. 
// The test cases are generated such that you can reach nums[n - 1]. 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
// Jump 1 step from index 0 to 1, then 3 steps to the last index.

#include<vector>
#include<climits>
using namespace std;


class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
            // we need to minimize the jumpbs
            vector<int> dp(n, INT_MAX);
    
            // first one you can always reach without jump
            dp[0] = 0;
    
            for(int i=1; i<n; i++) {
                for(int j=i-1; j>=0; j--) {
                    if(j + nums[j] >= i) {
                        // we have 1 more way than dp[j] to reach
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
    
            return dp[n-1];
    
        }
    };
