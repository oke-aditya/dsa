// Find the Rotation Count in RIGHT Rotated Sorted array
// Consider an array of distinct numbers sorted in increasing order.
// The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.

// Also

// Find minimum in rotated sorted array.
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// This gives the index of minimum element. We can use this to solve

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

int count_rightrot(vector<int> arr)
{
    int n = arr.size();
    int left = 0, right = n - 1;
    if (arr[left] <= arr[right]) {
        return 0;
    }
   
    while (left <= right) {

        // if first element is mid or
        // last element is mid
        // then simply use modulo so it
        // never goes out of bound.
        int mid = left + (right - left) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;

        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;
        else if (arr[mid] <= arr[right])
            right = mid - 1;
        else if (arr[mid] >= arr[0])
            left = mid + 1;
    }

    return 0;
}

// To calculate left rotations, do the same, answer is (n - pivot) % n.

int main(int argc, char const *argv[])
{
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = count_rightrot(arr);
    cout << res << endl;
    return 0;
}
