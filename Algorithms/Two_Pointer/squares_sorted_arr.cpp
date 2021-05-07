// Given an integer array nums sorted in non-decreasing order, return an
// array of the squares of each number sorted in non-decreasing order.

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

// Solution: -
// Square each element and sort the resultant array.
// 

// Two pointer solution: -
// Keep two pointers, square only the element which is abs() bigger.
// 



#include<bits/stdc++.h>

using namespace std;

vector<int> sortedSquares(vector<int>& nums)
{
    int left=0, right=nums.size()-1;
    vector <int> res;

    while(left <= right)
    {
        if(abs(nums[left]) > abs(nums[right]))
        {
            res.push_back(nums[left] * nums[left]);
            left += 1;
        }
        else
        {
            res.push_back(nums[right] * nums[right]);
            right -= 1;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
