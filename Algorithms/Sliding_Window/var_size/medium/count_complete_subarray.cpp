// https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/

// You are given an array nums consisting of positive integers.
// We call a subarray of an array complete if the following condition is satisfied:
// The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.

// Return the number of complete subarrays.
// A subarray is a contiguous non-empty part of an array.

// Example 1:

// Input: nums = [1,3,1,2,2]
// Output: 4
// Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].

// Example 2:

// Input: nums = [5,5,5,5]
// Output: 10
// Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.

// Use the atmost concept as we want number of windows equal to size k
// Length of window should be added to the answer.
// Use map to track elements, set will prematurely delete items
// 

#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:

    int atMost(vector<int> &nums, int k) {
        if(k <= 0) {
            return 0;
        }

        int count = 0, i = 0;
        unordered_map<int, int> mp;

        for(int j=0; j<nums.size(); j++) {
            mp[nums[j]] += 1;

            while(mp.size() > k) {
                mp[nums[i]] -= 1;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i += 1;
            }

            count += (j - i + 1);
        }

        return count;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        int k = st.size();

        return atMost(nums, k) - atMost(nums, k-1);


    }
};