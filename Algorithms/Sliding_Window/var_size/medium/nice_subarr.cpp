// https://leetcode.com/problems/count-number-of-nice-subarrays/

// Given an array of integers nums and an integer k. A continuous subarray is
// called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and
// [1,2,1,1].

// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There is no odd numbers in the array.

// Solution:
// Trick is simple.
// we can also do an alternate trick.
// similar to binary sub array sum
// note the trick, it works if we want to count atleast k.
// here we want exact k, so we do atleast k - atleast k-1;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int sub_arr_count(vector<int> nums, int k) {
        int count = 0, n = nums.size(), odd_count = 0, i = 0;
        
        for(int j=0; j<n; j++) {
            
            if(nums[j] % 2) {
                odd_count += 1;
            }

            while(odd_count > k) {
                if(nums[i] % 2) {
                    odd_count -= 1;
                }
                i += 1;
            }
            count += (j - i + 1);
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return sub_arr_count(nums, k) - sub_arr_count(nums, k - 1);
    }
};
