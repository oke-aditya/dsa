// https://leetcode.com/problems/maximum-erasure-value/description/

// You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
// The score you get by erasing the subarray is equal to the sum of its elements.

// Return the maximum score you can get by erasing exactly one subarray.

// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, 
// that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

// Example 1:

// Input: nums = [4,2,4,5,6]
// Output: 17
// Explanation: The optimal subarray here is [2,4,5,6].

// Example 2:

// Input: nums = [5,2,1,2,5,2,1,2,5]
// Output: 8

// Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

// Solution:
// Use a sliding window and hashmap to keep track of unique elements
// in case element occurs twice, clear from left side of array and erase from hashmap
// Keep track of maximum sum that is obtained at every step

#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int max_erasure = 0, curr_sum = 0, n = nums.size();
        int i = 0;
        unordered_map<int, int> mp;

        for(int j=0; j<n; j++) {
            mp[nums[j]] += 1;

            // not unique
            if(mp[nums[j]] > 1) {
                
                // cout<<"Y"<<endl;

                while(mp[nums[j]] > 1) {
                    mp[nums[i]] -= 1;

                    curr_sum -= nums[i];
                    // cout<<"cy: "<< curr_sum<<endl;

                    if(mp[nums[i]] == 0) {
                        mp.erase(nums[i]);
                    }
                    i += 1;
                }
            }

            curr_sum += nums[j];
            
            // cout<<curr_sum<<endl;

            max_erasure = max(max_erasure, curr_sum);
        }

        return max_erasure;

    }
};
