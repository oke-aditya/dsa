// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/

// You are given an integer array nums and a positive integer k.

// A subsequence sub of nums with length x is called valid if it satisfies:
// (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
// Return the length of the longest valid subsequence of nums.


// Example 1:

// Input: nums = [1,2,3,4,5], k = 2
// Output: 5

// Explanation:

// The longest valid subsequence is [1, 2, 3, 4, 5].

// Example 2:

// Input: nums = [1,4,2,3,1,4], k = 3

// Output: 4

// Explanation:
// The longest valid subsequence is [1, 4, 1, 4].

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        // [{mod, len}, {mod, len}, {mod, len}]
        vector<unordered_map<int, int>> dp(n);

        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>i; j--) {
                
                int mod = (nums[j] + nums[i]) % k;

                if(dp[j].find(mod) == dp[j].end()) {
                    dp[i][mod] = 2;
                }

                else {
                    dp[i][mod] = 1 + dp[j][mod];
                }
            }
        }

        int max_len = 0;
        for(int i=0; i<n; i++) {
            for(auto it: dp[i]) {
                max_len = max(max_len, it.second);
            }
        }

        return max_len;
    
    }
};
