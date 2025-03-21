// https://leetcode.com/problems/count-number-of-nice-subarrays/

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There is no odd numbers in the array.

// Solution:
// Trick is simple. 
// Keep track when we have odd and odd count hits the k threshold
// If it does hit that, then we can decrement the odd count and start counting from left pointer
// Add these counts to restul



#include<bits/stdc++.h>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) 
{
    int i=0, j = 0, count = 0;
    int res = 0;
    int n = nums.size();
    int odd_count = 0;

    for(int j=0; j<n; j++) {

        // odd no
        if(nums[j] % 2 == 1) 
        {
            odd_count += 1;

            if(odd_count == k) 
            {
                count = 0;
                // while we have even numbers on the left
                while(odd_count == k) {
                    if(nums[i] % 2 == 1) {
                        odd_count -= 1;
                    }
                    i += 1;
                    count += 1;
                }
            }
        }
        res += count;
    }
    return res;
}