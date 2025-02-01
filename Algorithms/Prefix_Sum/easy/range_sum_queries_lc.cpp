// https://leetcode.com/problems/range-sum-query-immutable/description/

// Given an integer array nums, handle multiple queries of the following type:

//     Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

// Implement the NumArray class:

//     NumArray(int[] nums) Initializes the object with the integer array nums.
//     int sumRange(int left, int right) Returns the sum of the elements 
//     of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

 

// Example 1:

// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]

// Explanation
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
// numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
// numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3


#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:

    // In the constructor we can implement and save prefix sum
    // this prefix sum then we can use when queries go left, right;

    void print_v(vector<int> v)
    {
        for(auto x : v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    vector<long long> prefix_sum;

    NumArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long long> prefix_sum(n + 1);

        for(int i=1; i<=n; i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
        }

        this->prefix_sum = prefix_sum;
    }
    
    int sumRange(int left, int right) 
    {
        // print_v(prefix_sum);
        return (prefix_sum[right+1] - prefix_sum[left]);
    }

};

