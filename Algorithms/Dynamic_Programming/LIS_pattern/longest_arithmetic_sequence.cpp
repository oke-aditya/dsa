// https://leetcode.com/problems/longest-arithmetic-subsequence/

// Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

// Note that:

// A subsequence is an array that can be derived from another array by deleting some 
// or no elements without changing the order of the remaining elements.

// A sequence seq is arithmetic if seq[i + 1] - seq[i] 
// are all the same value (for 0 <= i < seq.length - 1).

// Example 1:

// Input: nums = [3,6,9,12]
// Output: 4
// Explanation:  The whole array is an arithmetic sequence with steps of length = 3.

// Example 2:

// Input: nums = [9,4,7,2,10]
// Output: 3
// Explanation:  The longest arithmetic subsequence is [4,7,10].

#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        // [{diff, len}, {diff, len}, {diff, len}]
        vector<unordered_map<int, int>> dp(n);
        

        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>i; j--) {

                int diff = nums[j] - nums[i];

                if(dp[j].find(diff) == dp[j].end()) {
                    dp[i][diff] = 2;
                }
                else {
                    dp[i][diff] = dp[j][diff] + 1;
                }
            }
        }

        int max_len = 0;

        for(int i=0; i<n; i++) {
            for(auto itr: dp[i]) {
                max_len = max(max_len, itr.second);
            }
        }

        return max_len;
    }
};
