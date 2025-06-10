// https://leetcode.com/problems/zero-array-transformation-ii/description/

// You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

// Each queries[i] represents the following action on nums:

// Decrement the value at each index in the range [li, ri] in nums by at most vali.
// The amount by which each value is decremented can be chosen independently for each index.

// A Zero Array is an array with all its elements equal to 0.

// Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

 

// Example 1:

// Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

// Output: 2

// Explanation:

//     For i = 0 (l = 0, r = 2, val = 1):
//         Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
//         The array will become [1, 0, 1].
//     For i = 1 (l = 0, r = 2, val = 1):
//         Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
//         The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.

// Example 2:

// Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]

// Output: -1

// Explanation:

//     For i = 0 (l = 1, r = 3, val = 2):
//         Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
//         The array will become [4, 1, 0, 0].
//     For i = 1 (l = 0, r = 2, val = 1):
//         Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
//         The array will become [3, 0, 0, 0], which is not a Zero Array.


// Solution:

// Use same idea as difference array from 1.
// Use binary search on queries to find best answer
// same solution as zero array first, with added binary search

#include<vector>
using namespace std;

class Solution {
public:

    bool is_possible(vector<int> nums, vector<vector<int>> queries, int k) {
        int n = nums.size();
        vector<int> prefix_sum(n+1, 0);

        // we need to consider only k queries
        for(int i=0; i<k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            // you need to decrement the value
            prefix_sum[l] += -val;
            prefix_sum[r+1] -= -val;
        }

        for(int i=1; i<=n; i++) {
            prefix_sum[i] += prefix_sum[i-1];
        }
        // it is possible if these prefix sum + nums makeit possible

        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                if((nums[i] + prefix_sum[i]) > 0) {
                    return false;
                }
            }
        }
        return true;
    
    }


    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int res = -1;
        int n = queries.size();
        int left = 0, right = n;

        while(left <= right) {
            int mid = left + (right - left ) / 2;

            // try finding a better answer
            // and store this ans
            if(is_possible(nums, queries, mid)) {
                res = mid;
                right = mid - 1;
            }

            // not sure we can chop the search space one side? 
            else {
                left = mid + 1;
            }
        }

        return res;      

    }
};
