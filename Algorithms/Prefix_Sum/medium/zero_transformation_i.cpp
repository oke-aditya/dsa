// // https://leetcode.com/problems/zero-array-transformation-i/description/

// You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
// For each queries[i]:

// Select a subset of indices within the range [li, ri] in nums.
// Decrement the values at the selected indices by 1.

// A Zero Array is an array where all elements are equal to 0.

// Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

// Example 1:

// Input: nums = [1,0,1], queries = [[0,2]]

// Output: true

// Explanation:

// For i = 0:
//     Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
//     The array will become [0, 0, 0], which is a Zero Array.

// Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]

// Output: false

// Explanation:

//     For i = 0:
//         Select the subset of indices as [1, 2, 3] and decrement the values at these indices by 1.
//         The array will become [4, 2, 1, 0].
//     For i = 1:
//         Select the subset of indices as [0, 1, 2] and decrement the values at these indices by 1.
//         The array will become [3, 1, 0, 0], which is not a Zero Array.

// Solution:
// Trick is very similar here.
// We do maintain difference array like range addition
// on left side add -1 and on right side subtract -1
// Accumulate the prefix sum
// now check if accumulated sum + nums[i] will be greater than 0.
// then we do not have enough decrements so return false.
    

#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:

    void print_v(vector<int> v) {
        for(auto x: v) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix_sum(n+1, 0);


        for(auto q: queries) {
            int l = q[0];
            int r = q[1];

            prefix_sum[l] += -1;
            prefix_sum[r+1] -= -1;
        }

        for(int i=1; i<=n; i++) {
            prefix_sum[i] += prefix_sum[i-1];
        }

        // print_v(prefix_sum);

        bool is_possible = true;
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                if((nums[i] + prefix_sum[i]) > 0) {
                    is_possible = false;
                    break;
                }
            }
        }

        return is_possible;


    }
};