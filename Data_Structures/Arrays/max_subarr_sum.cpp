// Given an integer array nums,
// find the contiguous subarray (containing at least one number)
// which has the largest sum and return its sum.

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// Solution: -

// We need to use Kadane's algorithm.
// Keep a track of sum so far.
// If sum so far is -ve set it to 0
// Add the new element to sum only if net sum is +ve
// Update maximum sum with sum.


#include<bits/stdc++.h>
using namespace std;

int max_sub_arr(vector <int> v)
{
    int sum_so_far = 0;
    int max_sum = v[0];

    for(int i=0; i<v.size(); i++)
    {
        sum_so_far += v[i];
        if(sum_so_far > max_sum)
        {
            max_sum = sum_so_far;
        }
        if(sum_so_far < 0)
        {
            sum_so_far = 0;
        }
    }
    return max_sum;

}

int main(int argc, char const *argv[])
{
    vector <int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    auto res = max_sub_arr(v);
    cout<<res<<endl;

    return 0;
}

