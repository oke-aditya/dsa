// Given an integer array nums of 2n integers, group these integers into n pairs
// (a1, b1), (a2, b2), ..., (an, bn)
// such that the sum of min(ai, bi) for all i is maximized.
// Return the maximized sum.

// https://leetcode.com/problems/array-partition-i/

// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

// Example 2:

// Input: arr = [1,2]
// Output: false

// Example 3:

// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
// Output: true

// Solution: -
// Sort the array.
// Elements are now paired. Add all the even indices.
// That gives the sum_diff.


#include <bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int sum_diff = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
        {
            sum_diff += nums[i];
        }
    }

    return sum_diff;
}
