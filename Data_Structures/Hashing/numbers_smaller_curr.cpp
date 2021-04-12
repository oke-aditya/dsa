// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.
// That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

// Return the answer in an array.

// Input: nums = [8,1,2,2,3]
// Output: [4,0,1,1,3]
// Explanation: 
// For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
// For nums[1]=1 does not exist any smaller number than it.
// For nums[2]=2 there exist one smaller number than it (1). 
// For nums[3]=2 there exist one smaller number than it (1). 
// For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).


// Example 2:

// Input: nums = [6,5,4,8]
// Output: [2,1,0,3]

// Example 3:

// Input: nums = [7,7,7,7]
// Output: [0,0,0,0]


// Solution: -
// Store the count in a bucket and take the running sum.
// 


#include<bits/stdc++.h>
using namespace std;

void print_v(vector <int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


// 2 <= nums.length <= 500
// 0 <= nums[i] <= 100


vector <int> number_smaller(vector <int> &nums)
{

}



int main(int argc, char const *argv[])
{
    vector <int> nums = {8, 1, 2, 2, 3};
    auto res = number_smaller(nums);

    return 0;
}


