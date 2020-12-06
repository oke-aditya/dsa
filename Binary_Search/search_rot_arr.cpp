// You are given an integer array nums sorted in ascending order, and an integer target.

// Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// If target is found in the array return its index, otherwise, return -1.

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Input: nums = [3,4,5,6,7,1,2], target = 4
// Output: 1

// Input: nums = [6,7,1,2,3,4,5], target = 1
// Output: 2


#include <bits/stdc++.h>
using namespace std;

int search_rot_arr(int arr[], int n, int tgt)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == tgt)
        {
            return mid;
        }
        
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = search_rot_arr(arr, n, target);
    cout << res << endl;

    return 0;
}
