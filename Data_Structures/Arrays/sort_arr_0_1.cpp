// Given an array nums with n objects colored red, white, or blue, sort

// them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Could you solve this problem without using the library's sort function?
// Could you come up with a one-pass algorithm using only O(1) constant space?


#include<bits/stdc++.h>
using namespace std;

// 1. Naive solution: -
// Sort the array.
// Time Complexity O(nlogn)
// Space Complexity = O(1)

// 2. Counting Sort

// Count number of 0s
// Count number of 1s
// Count number of 2s.
// To existing array overwrite 0 x number of 0s, 1 x number of 1s, 2 x number of 2s

void sort_colors_counting(vector <int> nums)
{
    
}

void sortColors(vector<int>& nums)
{
    int n = nums.size();

}


int main(int argc, char const *argv[])
{
    vector <int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);

    return 0;
}

