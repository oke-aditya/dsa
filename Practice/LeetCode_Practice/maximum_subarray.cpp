// Given an integer array nums, 
// find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.


// Kadane's Algorithm

// Iterate through arr while maintaining curSum
// Any negative prefix will not contribute to the future maximum
// Therefore, if curSum becomes negative, reset curSum to 0
// Similar to sliding window, where we update window if prefix is negative

#include<iostream>
#include<vector>
using namespace std;

int MaxSubarray(vector <int> &nums)
{
    int maxSub = nums[0];
    int curSum = 0;

    for(auto &num : nums)
    {
        if (curSum < 0)
        {
            curSum = 0;
        }
        curSum += num;
        maxSub = max(maxSub, curSum);
    }
    return maxSub;
}

int main(int argc, char const *argv[])
{
    vector <int> v1 {-2, 1, -3, 4, -1, 2, 1, -5 , 4};
    cout<<MaxSubarray(v1);

    return 0;
}


