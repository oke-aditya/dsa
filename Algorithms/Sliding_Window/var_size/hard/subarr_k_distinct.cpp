// https://leetcode.com/problems/subarrays-with-k-different-integers/description/

// Given an integer array nums and an integer k, return the number of good
// subarrays of nums.

// A good array is an array where the number of different integers in that array
// is exactly k.

//     For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2],
// [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

// Example 2:

// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3],
// [2,1,3], [1,3,4].

// Solution:
// The trick is again same, since we need count of exact "K"
// We get the count of atleast k and atleast k - 1;
// Difference of these 2 will give the answer
// to keep track of number of distinct we can use a map to save them


#include<unordered_map>
#include<vector>

using namespace std;


class Solution {
    public:
    
        int sub_arr_count(vector<int> nums, int k) {
            if(k == 0)
                return 0;
    
            int n = nums.size(), count = 0, i = 0, j = 0;
            unordered_map<int, int> mp;
    
    
            for(j=0; j<n; j++) {
                mp[nums[j]] += 1;
    
                // count of distinct would be map size
                while(mp.size() > k) {
                    mp[nums[i]] -= 1;
                    if(mp[nums[i]]  == 0) {
                        mp.erase(nums[i]);
                    }
                    i += 1;
                }
    
                count += (j - i + 1);
            }
    
    
            return count;
        }
    
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            return sub_arr_count(nums, k) - sub_arr_count(nums, k-1);
        }
    };
