// https://leetcode.com/problems/subarray-sum-equals-k/description/

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2

// Solution:

// This is pretty easy with sliding window if we have only positive numbers
// since we have negative numbers, sliding window will not work
// We will have to resort to prefix sum to store the results.

// most easy solution is to consider all the subarrays, O(n2)

#include <unordered_map>
#include<vector>
using namespace std;

int subarraySumBrute(vector<int>& nums, int k) {
    int count = 0, n = nums.size();

    for(int i=0; i<n; i++) {
        int sum = nums[i];
        if(sum == k) {
            count += 1;
        }
        for(int j=i+1; j<n; j++) {
            sum += nums[j];
            if(sum == k) {
                count += 1;
            }
        }
    }

    return count;
}

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefix_sum(n + 1, 0);

    // standard prefix sum computation
    for(int i=1; i<=n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
    }

    int count = 0;
    unordered_map<int, int> mp;

    // now if prefix sum is same as k 
    // we have answer
    for(int i=1; i<=n; i++) {
        if(prefix_sum[i] == k) {
            count += 1;
        }

        // we find prefix sum[i] - k if it has occured
        if(mp.find(prefix_sum[i] - k) != mp.end()) {
            count += mp[prefix_sum[i] - k];
        }
        
        // two sum trick, store it
        mp[prefix_sum[i]] += 1;
    }

    return count;

}
