// A peak element is an element that is strictly greater than its neighbors.
// Given an integer array nums, find a peak element, and return its index.
// If the array contains multiple peaks, return the index to any of the peaks.

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2,
// or index number 5 where the peak element is 6.

#include <bits/stdc++.h>
using namespace std;

int peak_element(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (mid > 0 && mid < n - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid - 1] > arr[mid])
            {
                // If left element is greater, we should search on left.
                right = mid - 1;
            }
            else if (arr[mid + 1] > arr[mid])
            {
                // If right element is greater, we should search on right.
                left = mid + 1;
            }
        }
        // Edge cases
        else if (mid == 0)
        {
            if (arr[0] > arr[1])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if (mid == n - 1)
        {
            if (arr[n - 1] > arr[n - 2])
            {
                return n - 1;
            }
            else
            {
                return n - 2;
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 1, 3, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int res = peak_element(arr, n);
    cout << res << endl;

    return 0;
}
