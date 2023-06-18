// https://leetcode.com/problems/find-peak-element/

// A peak element is an element that is strictly 
// greater than its neighbors.
// Given an integer array nums, find a peak element,
//  and return its index.
// If the array contains multiple peaks, 
// return the index to any of the peaks.

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either 
// index number 1 where the peak element is 2,
// or index number 5 where the peak element is 6.

#include <bits/stdc++.h>    
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if(nums.size() == 1) {
        return 0;
    }

    int left = 0, right = n - 1, mid;

    while(left <= right) {
        
        mid = left + (right - left) / 2;

        if(mid > 0 && mid < n - 1) {            
            // condn for peak element.
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            else if(nums[mid - 1] > nums[mid]) {
                right = mid - 1;
            }

            else if(nums[mid + 1] > nums[mid]) {
                left = mid + 1;
            }

        }

        else if (mid == 0) {
            if(nums[0] > nums[1]) {
                return 0;
            }
            else {
                return 1;
            }
        }

        else if(mid == n - 1) {
            if(nums[n - 1] > nums[n - 2]) {
                return n - 1;
            }
            else {
                return n - 2;
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 1, 3, 5, 6, 4};
    // int n = sizeof(arr) / sizeof(arr[0]);

    int res = findPeakElement(v);
    cout << res << endl;

    return 0;
}
