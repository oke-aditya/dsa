// https://leetcode.com/problems/minimum-size-subarray-sum/

// Given an array of positive integers nums and a positive integer target,
// return the minimal length of a contiguous subarray
// [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than
// or equal to target. If there is no such subarray, return 0 instead.

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1

// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0


#include<bits/stdc++.h>
using namespace std;

// This works only for case when it is equal
// Does not work when greater than equal (as in qs)

int min_sum_subarr(vector <int> nums, int target)
{
    int min_win_size = INT_MAX, n = nums.size();
    int i=0, j = 0;
    int win_sum = 0;

    for(int j=0; j<n; j++)
    {
        win_sum += nums[j];
        if(win_sum >= target)
        {
            min_win_size = min(min_win_size, (j - i + 1));
        }
        while(win_sum >= target)
        {
            min_win_size = min(min_win_size, (j - i + 1));
            win_sum -= nums[i];
            i += 1;
        }
    }
    
    if(min_win_size == INT_MAX)
    {
        return 0;
    }
    else
    {
        return min_win_size;
    }
}



int main(int argc, char const *argv[])
{
    vector <int> v1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;

    vector <int> v2 = {1, 4, 4};
    int target2 = 4;

    vector <int> v3 = {1, 1, 1, 1, 1, 1 , 1 , 1};
    int target3 = 11;

    auto res1 = min_sum_subarr(v1, target1);
    auto res2 = min_sum_subarr(v2, target2);
    auto res3 = min_sum_subarr(v3, target3);

    return 0;
}

