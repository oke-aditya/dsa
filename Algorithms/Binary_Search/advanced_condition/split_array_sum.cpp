// https://leetcode.com/problems/split-array-largest-sum/description/

// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
// Return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

// Solution:
// Idea is same as painter partition / book allocation problem
// Cur the array into possible max sum paritions
// Check the count of partition
// return if it's valid.


#include <numeric>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    public:
    
        bool is_possible(vector<int> &nums, int max_sum, int k) {
            // we already have 1 partition, if we cut once, we get 2 partitions
            int calc_sum = 0, n_part = 1;
    
            for(int i=0; i<nums.size(); i++) {
                
                // we need a new partition
                if(nums[i] + calc_sum > max_sum) {
                    n_part += 1;
                    // reset the calc_sum
                    calc_sum = nums[i];
                }
    
                else {
                    calc_sum += nums[i];
                }
            }
    
            return (n_part <= k);
    
        }
    
    
        int splitArray(vector<int>& nums, int k) {
            int left = *max_element(begin(nums), end(nums));
            int right = accumulate(begin(nums), end(nums), 0);
            int ans = 0;
    
            // allocate these many values what mid gives
            // see the number of partitions needed and then search
    
            while(left <= right) {
                int mid = left + (right - left) / 2;
    
                // check for better solution on left
                // mid contains sum that was used to divide
                // that is the max sum to divide
                if(is_possible(nums, mid, k)) {
                    ans = mid;
                    right = mid - 1;
                }
    
                else {
                    left = mid + 1;
                }
            }
    
            return ans;
    
        }
    };
