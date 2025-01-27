// https://leetcode.com/problems/range-addition/description/

// Assume you have an array of length n initialized with all 0's and are given k update operations.

// Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray 
// A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

// Return the modified array after all k operations were executed.

// Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
// Output: [-2,0,3,5,3]

// Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
// Output: [0,-4,2,2,2,4,4,-4,-4,-4]

// Solution
// the steps would look like these
// [0 0 0 0 0]
// [0 2 2 2 0]
// [0 2 5 5 3]
// [-2 0 3 5 3]
// 
// Range Update with Difference Array:

// For each operation [start, end, inc], 
// we add inc to nums[start] and subtract inc from nums[end + 1] (if end + 1 < n).
// This ensures that we mark where the increment starts and where it ends.

// Prefix Sum Calculation: After applying all the operations, 
// we iterate through the array and accumulate the values to get the final result.
// 


#include<bits/stdc++.h>

using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
{
    // the array is all zeros
    vector<int> nums(length);

    for (auto q: updates)
    {
        int left = q[0];
        int right = q[1];
        int inc = q[2];

        nums[left] += inc;

        if(right + 1 < length)
            nums[right+1] -= inc;
    }

    for(int i=1; i<length; i++)
    {
        nums[i] += nums[i-1];
    }

    return nums;

}



