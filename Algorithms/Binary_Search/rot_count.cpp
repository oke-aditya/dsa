// Find the Rotation Count in RIGHT Rotated Sorted array
// Consider an array of distinct numbers sorted in increasing order.
// The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.

// Examples:

// Input : arr[] = {15, 18, 2, 3, 6, 12}
// Output: 2
// Explanation : Initial array must be {2, 3,
// 6, 12, 15, 18}. We get the given array after
// rotating the initial array twice.

// Input : arr[] = {7, 9, 11, 12, 5}
// Output: 4

// Input: arr[] = {7, 9, 11, 12, 15};
// Output: 0

// Solution: - We have to find the location of minimum value in the array.

// Minimum location is jammed between 2 ascending arrays. Previous element is greater,
// next element is smaller.
// If there is no previous element, then there is no rotation (first element is minimum).
// We check this condition for middle element by comparing it with (mid-1)’th and (mid+1)’th elements.

// If the minimum element is not at the middle (neither mid nor mid + 1), then minimum element lies in either start half or right half.

//     If middle element is smaller than last element, then the minimum element lies in left half
//     Else minimum element lies in right half.

#include <bits/stdc++.h>
using namespace std;

int count_rightrot(int arr[], int n)
{
    int start = 0, end = n - 1;
    int pivot = -1;

    // There is only one element
    if (arr[start] < arr[end])
    {
        return 0;
    }
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int next = (mid + 1) % n;     // % n for restricting overflow
        int prev = (mid - 1 + n) % n; // add n and % n for start overflow

        // Middle element is jam packed, less than both the ends.
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
        {
            pivot = mid;
            break;
        }
        if (arr[start] <= arr[mid])
        {
            // search on end as middle is greater than start
            start = mid + 1;
        }
        else if (arr[mid] <= arr[end])
        {
            // search on left as middle is smaller
            end = mid - 1;
        }
    }
    return pivot;
}

// To calculate left rotations, do the same, answer is (n - pivot) % n.

int main(int argc, char const *argv[])
{
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = count_rightrot(arr, n);
    cout << res << endl;
    return 0;
}
