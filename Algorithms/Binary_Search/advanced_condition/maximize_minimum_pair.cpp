// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

// You are given a 0-indexed integer array nums and an integer p. 
// Find p pairs of indices of nums such that the maximum difference amongst 
// all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

// Note that for a pair of elements at the index i and j, the difference of 
// this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

// Return the minimum maximum difference among all p pairs. 
// We define the maximum of an empty set to be zero.

// Example 1:

// Input: nums = [10,1,2,7,1,3], p = 2
// Output: 1
// Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
// The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool is_possible(vector<int> nums, int mid, int p) {
        // now find if p pairs are possible for mid amount
        int count = 0, i = 0;

        while(i < nums.size() - 1) {
            if((nums[i+1] - nums[i]) <= mid) {
                count += 1;
                i += 2;
            }
            else {
                i += 1;
            }
            if(count >= p) {
                return true;
            }
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        // this is hard
        // trick is to try out a number and see if it can be achieved

        sort(begin(nums), end(nums));
        int left = 0, right = nums.back() - nums[0], res = 0;

        while(left < right) { 
            int mid = left + (right - left) / 2;

            // if it is possible to satisfy p pairs in mid
            if(is_possible(nums, mid, p)) {
                right = mid;
                // right = mid - 1;
            }

            else {
                left = mid + 1;
            }

        }

        return left;

    }
};