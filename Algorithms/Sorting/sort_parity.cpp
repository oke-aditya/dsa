// Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

// Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

// Return any answer array that satisfies this condition.

// Example 1:

// Input: nums = [4,2,5,7]
// Output: [4,5,2,7]
// Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

// Example 2:

// Input: nums = [2,3]
// Output: [2,3]

#include<bits/stdc++.h>

using namespace std;

// Two pass solution

vector<int> sortArrayByParityII(vector<int>& nums)
{
    vector <int> res(nums.size(), 0);
    int i = 0;

    for(int num: nums)
    {
        if((num % 2) == 0)
        {
            res[i] = num;
            i += 2;
        }
    }

    i = 1;
    for(int num: nums)
    {
        if((num % 2) == 1)
        {
            res[i] = num;
            i += 2;
        }
    }
    return res;
}

// One pass solution inplace

vector<int> sortArrayByParityII(vector<int>& nums)
{
    vector <int> res(nums.size(), 0);
    int i = 0, j = 1;

    for(int num: nums)
    {
        if((num % 2) == 0)
        {
            res[i] = num;
            i += 2;
        }
        else
        {
            res[j] = num;
            j += 2;
        }
        
    }
    return nums;
}


