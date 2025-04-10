// https://leetcode.com/problems/3sum-closest/

// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

// Solution:
// Brute force would work for smaller inputs too
// You can just check 3 numbers and their summ
// if the calculated difference is less than minimum one
// The sum becomes the result

// Optimized solution:

// this is close to three sum
// we will sort the array and try to do three sum logic



#include <algorithm>
#include <climits>
#include <cstdlib>
#include<vector>

using namespace std;;


int threeSumClosestBrute(vector<int>& nums, int target) {
    int i=0, j=0, k=0, n = nums.size();

    int min_diff = INT_MAX, calc_diff = INT_MAX;
    int sum = 0, res = 0;

    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                // cout<<i<<" "<<j<<" "<<k;
                sum = nums[i] + nums[j] + nums[k];
                // cout<<"sm: "<<sum<<" ";
                calc_diff = abs(target - sum);
                // cout<<"cd: "<<calc_diff<<" ";
                if(calc_diff < min_diff) {
                    min_diff = calc_diff;
                    res = sum;
                }
            }
        }
    }
    return res;
}

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();

    int min_diff = INT_MAX, calc_diff = INT_MAX;
    int sum = 0, res = 0;

    sort(begin(nums), end(nums));

    for(int i=0; i<n-2; i++) {
        int left = i + 1;
        int right = n - 1;

        while(left < right) {

            sum = nums[i] + nums[left] + nums[right];

            // cout<<" left: "<<nums[left]<<" right: "<<nums[right];
            // cout<<" sm: "<<sum;
            calc_diff = abs(target - sum);
            // cout<<" cd: "<<calc_diff;

            if(calc_diff < min_diff) {
                min_diff = calc_diff;
                res = sum;
            }

            // compare the sum and target
            // then decide the two pointer direction
            if(sum < target) {
                left += 1;
            }

            else if(sum > target) {
                right -= 1;
            }

            else {
                return sum;
            }
        }
    }

    return res;

}