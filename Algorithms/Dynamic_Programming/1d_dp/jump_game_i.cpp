// https://leetcode.com/problems/jump-game/description/

// You are given an integer array nums. 
// You are initially positioned at the array's first index, 
// and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. 
// Its maximum jump length is 0, which makes it impossible to reach the last index.

#include<vector>
using namespace std;


class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            vector<bool> dp(n, false);
    
            // we can always reach the first number
            dp[0] = true;
    
            for(int i=1; i<n; i++) {
                // traverse backwawrd
                // see if every positions we can reach or not
                for(int j=i-1; j>=0; j--) {
    
                    // if we could reach this index then which ones we can reach next
                    // we need j + nums[j], j is to offset the location and nums[j] for it's value
                    if(dp[j] && j + nums[j] >= i) {
                        dp[i] = true;
                        // we can break as we have determined what to do for i.
                        break;
                    }
                }
            }
    
            // question is can we reach the last one? 
            return dp[n-1];
    
        }
    };

